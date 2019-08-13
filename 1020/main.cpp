//上部分为2019年暑假刷题
#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
int post[N],in[N],n,cnt;
queue<bt*> qb;
bt* postInBuildTree(int post[],int in[],int n) {
    if (n<=0)   return nullptr;
    int i=0;
    while (post[n-1]!=in[i])    i++;
    bt* nw=new bt;
    nw->data=post[n-1];
    nw->lc=postInBuildTree(post,in,i);
    nw->rc=postInBuildTree(post+i,in+i+1,n-i-1);
    return nw;
}
void levelTraversal(bt* root)   {
    if (root==nullptr) return;
    qb.push(root);
    while (!qb.empty()) {
        bt* ts=qb.front();qb.pop();
        if (ts->lc) qb.push(ts->lc);
        if (ts->rc) qb.push(ts->rc);
        cnt++;
        printf("%d%c",ts->data,cnt==n?'\n':' ');
    }
}
int main()  {
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    bt* root=postInBuildTree(post,in,n);
    levelTraversal(root);
    return 0;
}






//#include <bits/stdc++.h>
//using namespace std;
//struct Node {
//    int data;
//    Node *ln,*rn;
//};
//Node* buildTree(int n,int post[],int inorder[]);
//void bfs();
//Node* root;
//queue<Node*> que;
//int main()  {
//    int n,pt[35],it[35];
//    scanf("%d",&n);
//    for (int i=0;i<n;i++)   scanf("%d",&pt[i]);
//    for (int i=0;i<n;i++)   scanf("%d",&it[i]);
//    root=buildTree(n,pt,it);
//    bfs();
//    return 0;
//}
//
//Node* buildTree(int n,int post[],int inorder[]) {
//    if (n<=0)   return NULL;
//    int i=0;
//    while (inorder[i]!=post[n-1])   i++;
//    Node *newnode=new Node;
//    newnode->data=inorder[i];
//    newnode->ln=buildTree(i,post,inorder);
//    newnode->rn=buildTree(n-i-1,post+i,inorder+i+1);
//    return newnode;
//}
//
//void bfs()  {
//    que.push(root);
//    while (!que.empty())    {
//        Node* tnode;
//        tnode=que.front();que.pop();
//        if (tnode->ln!=NULL)  que.push(tnode->ln);
//        if (tnode->rn!=NULL)  que.push(tnode->rn);
//        cout<<tnode->data;
//        if (!que.empty())   cout<<' ';
//        else    cout<<endl;
//    }
//}
