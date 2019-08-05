//这道题先放着里，我想用顺序树来做，但是没做出来
#include <bits/stdc++.h>
#define N 100
using namespace std;
int a[N],b[N],cnt,tree[N],n;      //a是post，b是in
void buildTree(int post[],int in[],int pl,int ph,int il,int ih);
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&a[i]);
    for (int i=0;i<n;i++)   scanf("%d",&b[i]);
    buildTree(a,b,0,n-1,0,n-1);
    for (int i=0;i<n;i++)
        printf("%d ",tree[i]);
    printf("\n");
    return 0;
}

void buildTree(int post[],int in[],int pl,int ph,int il,int ih)  {
    cout<<pl<<' '<<ph<<' '<<il<<' '<<ih<<endl;
    if (pl>ph)  return;
    if (cnt>=n) return;
    if (tree[++cnt]!=0) return;
    tree[cnt]=post[ph];
    printf("ori cnt=%d \t now root = %d\n",cnt-1,post[ph]);
    int i=pl;
    while (in[i]!=post[ph]) i++;
    buildTree(post,in,pl,pl+i-1,il,il+i-1);     //左子树
    buildTree(post,in,pl+i,ph-1,il+i+1,ih);   //右子树
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
