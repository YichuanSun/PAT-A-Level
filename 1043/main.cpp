#include <bits/stdc++.h>
#define MAX 10000007
#define MIN -10000007
#define N 10005
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
bool isBST(bt* root);
bt* preInBuildTree(int pre[],int in[],int n);
bool inOrderJudgeBST(bt* root);
int pre[N],in[N];
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    bt* tree=preInBuildTree(pre,in,n);
    cout<<inOrderJudgeBST(tree)<<endl;
    return 0;
}
bool isBST(bt* root)    {       //我写的，不知道为什么，感觉挺蠢的，但是也能用
    if (root==nullptr) return true;
    int td[4]={-1,0,MAX};
    td[1]=root->data;
    if (root->lc)   td[0]=root->lc->data;
    if (root->rc)   td[2]=root->rc->data;
    bool jd=(td[0]<td[1])&&(td[1]<td[2]);
    return isBST(root->lc)&&isBST(root->rc)&&jd;
}
int predt=MIN;      //王道算法才用得上
bool inOrderJudgeBST(bt* root)  {       //王道书上的，基于中序遍历实现：完全二叉树的中序遍历序列是递增/递减序列
    bool bl,br;
    if (root==nullptr)  return true;
    else {
        bl=inOrderJudgeBST(root->lc);
        if (!bl||root->data<predt)  return false;
        predt=root->data;
        br=inOrderJudgeBST(root->rc);
        return br;
    }
}
bt* preInBuildTree(int pre[],int in[],int n)    {
    if (n<=0)   return nullptr;
    int i=0;
    while (i<n&&pre[0]!=in[i])  i++;
    bt* nw=new bt;
    nw->data=pre[0];
    nw->lc=preInBuildTree(pre+1,in,i);
    nw->rc=preInBuildTree(pre+i+1,in+i+1,n-i-1);
    return nw;
}












//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> save;
//int n;
//bool isBST=true,flag;
//struct Node{
//    Node* left;
//    Node* right;
//    int val;
//};
//bool cmpltoh(int a,int b)  {return a<=b;}
//bool cmphtol(int a,int b)   {return a>=b;}
//Node* buildTree(int l,int r,bool cmp(int,int))    {
//    if (!isBST) return NULL;
//    if (l>r)   return NULL;
//    Node* root=new Node();
//    root->val=save[l];
//    int mid;
//    for (mid=l+1;mid<=r;mid++)
//        if (!cmp(save[mid],save[l]))
//            break;
//    root->left=buildTree(l+1,mid-1,cmp);
//    for (int i=mid;i<=r;i++)  {
//        if  (save[i]!=save[l]&&cmp(save[i],save[l]))    {
//            isBST=false;
//            return NULL;
//        }
//    }
//    root->right=buildTree(mid,r,cmp);
//    return root;
//}
//
//void posttr(Node* root) {
//    if (root==NULL) return;
//    posttr(root->left);
//    posttr(root->right);
//    if (flag==false)    {   //这种设flag打印树的方法很巧妙
//        cout<<root->val;
//        flag=true;
//    }
//    else    cout<<' '<<root->val;
//}
//
//int main()  {
//    int t;
//    cin>>n;
//    for (int i=0;i<n;i++)   {
//        cin>>t;
//        save.push_back(t);
//    }
//    Node* root=buildTree(0,n-1,cmpltoh);
//    if (isBST)  {
//        cout<<"YES"<<endl;
//        posttr(root);
//        cout<<endl;
//        return 0;
//    }
//    isBST=true;
//    root=buildTree(0,n-1,cmphtol);
//    if (isBST)  {
//        cout<<"YES"<<endl;
//        posttr(root);
//        cout<<endl;
//    }
//    else    cout<<"NO"<<endl;
//    return 0;
//}
