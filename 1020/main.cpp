#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *ln,*rn;
};
Node* buildTree(int n,int post[],int inorder[]);
void bfs();
Node* root;
queue<Node*> que;
int main()  {
    int n,pt[35],it[35];
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&pt[i]);
    for (int i=0;i<n;i++)   scanf("%d",&it[i]);
    root=buildTree(n,pt,it);
    bfs();
    return 0;
}

Node* buildTree(int n,int post[],int inorder[]) {
    if (n<=0)   return NULL;
    int i=0;
    while (inorder[i]!=post[n-1])   i++;
    Node *newnode=new Node;
    newnode->data=inorder[i];
    newnode->ln=buildTree(i,post,inorder);
    newnode->rn=buildTree(n-i-1,post+i,inorder+i+1);
    return newnode;
}

void bfs()  {
    que.push(root);
    while (!que.empty())    {
        Node* tnode;
        tnode=que.front();que.pop();
        if (tnode->ln!=NULL)  que.push(tnode->ln);
        if (tnode->rn!=NULL)  que.push(tnode->rn);
        cout<<tnode->data;
        if (!que.empty())   cout<<' ';
        else    cout<<endl;
    }
}
