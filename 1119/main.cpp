//下面的注释是作者写的
/*
这题我开始做有点难以理解，后来想清楚了：我解释下
【1】 2 3 4 6 7 5
 2 6 7 4 5 3 【1】
 一定要记住，前序是根 左 右的
 遍历顺序而后序是左 右 根的遍
 历顺序那么通过确定后序中3在前
 序中的位置，那么就知道如何划分
 子树了，因为3一定是1的右子树的
 根，那么在前序中，3之前1之后
 的序列就是左子树，3到5之间都
 为右子树的一部分，再递归处理即可
 但是若根结点只有一颗子树，那么
 得确定到底是左还是右，自己决定
 这也是前+后不一定能唯一确定树的原因
 1 2 3 4
 2 4 3 1
 1为根，找右子树的根即3在前序中的位置
 那么2是左子树，3 4是右子树，继续递归
 2只有一个直接返回，3 4中3是根，4是子
 树，但是左还是右？自己决定，这种情况就是不能唯一确定
*/

//下面是我仿照大佬写的垃圾
#include <bits/stdc++.h>
#define N 105
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
int pre[N],post[N],n,flag=1,cnt;
bt* prePostBuildTree(int prel,int prer,int postl,int postr)  {
    if (prel>prer)  return nullptr;     //第二次加的
    bt* nw=new bt;
    nw->data=pre[prel];
    nw->lc=nullptr;nw->rc=nullptr;
    if (prel==prer) return nw;          //第二次加的
    int i=prel+1;
    while (i<=prer&&pre[i]!=post[postr-1])  i++;
    if (i>prel+1)   {
        nw->lc=prePostBuildTree(prel+1,i-1,postl,postl+i-prel-2);
        nw->rc=prePostBuildTree(i,prer,postl+i-prel-1,postr-1);
    }
    else{
        flag=0;
        nw->rc=prePostBuildTree(i,prer,postl+i-prel-1,postr-1);
    }
    return nw;
}
void inOrderTraversal(bt* root) {
    if (root==nullptr)  return;
    inOrderTraversal(root->lc);
    printf("%d%c",root->data,(cnt++)==n-1?'\n':' ');
    inOrderTraversal(root->rc);
}
int main()  {
    cin>>n;
    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
    bt* root=prePostBuildTree(0,n-1,0,n-1);
    printf("%s\n",flag?"Yes":"No");
    inOrderTraversal(root);
    return 0;
}
