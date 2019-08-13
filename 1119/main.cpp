#include <iostream>
using namespace std;
const int maxn = 31;

int n, index = 0;
int pre[maxn], post[maxn];
bool flag = true;

struct Node {
	int data;
	Node *lchild, *rchild;
} *root;

Node *create(int preL, int preR, int postL, int postR){
	if (preL > preR) return NULL;//不合理就返回NULL
	Node *node = new Node;//建立根结点
	node->data = pre[preL];
	node->lchild = NULL;
	node->rchild = NULL;
	if (preL == preR)
		return node;//若只有一个节点那么直接返回即可
	int k = 0;
	for (k = preL + 1; k <= preR; k++)
		if (pre[k] == post[postR - 1]) break;//从前序中找后序中子树根的位置
	if (k - preL > 1){
		node->lchild = create(preL + 1, k - 1, postL, postL + k - preL - 2);
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	else{
		flag = false;
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	return node;
}

void inOrder(Node *node){
	if (node == NULL) return;
	inOrder(node->lchild);
	if (index < n - 1)
		cout << node->data << " ";
	else cout << node->data << endl;
	index++;
	inOrder(node->rchild);
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pre[i];
	for (int i = 0; i < n; ++i) cin >> post[i];
	root = create(0, n - 1, 0, n - 1);
	if (flag) cout << "Yes\n";
	else cout << "No\n";
	inOrder(root);
	return 0;
}
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

//下面是我写的垃圾
//#include <bits/stdc++.h>
//#define N 105
//using namespace std;
//typedef struct bt{
//    int data;
//    bt *lc,*rc;
//}bt;
//int pre[N],post[N],n;
//bt* prePostBuildTree(int pre[],int post[],int n)  {
//    if (n<=0)   return nullptr;
//    int i=0;
//    while (pre[i]!=post[n-1])   i++;
//    bt *nw=new bt;
//    nw->data=post[n-1];
//    if (i==0)   {
//        nw->lc=prePostBuildTree(pre+1,post,i+1);
//        nw->rc=prePostBuildTree(pre+i+1,post+i+1,n-i-1);
//    }
//    else {
//        nw->lc=prePostBuildTree(pre+1,post,i+1);
//
//    }
//    return nw;
//}
//int main()  {
//    cin>>n;
//    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
//    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
//    buildTree();
//    return 0;
//}
