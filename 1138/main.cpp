#include <bits/stdc++.h>
#define N 50005
using namespace std;
int pre[N],in[N],cnt,n;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
bt* preInBuildTree(int pre[],int in[],int n);
void postOrder(bt* root);
int main(){
    cin>>n;
    for (int i=0; i<n; i++)cin>>pre[i];
    for (int i=0; i<n; i++)cin>>in[i];
    bt* root=preInBuildTree(pre,in,n);
    postOrder(root);
    return 0;
};

bt* preInBuildTree(int pre[],int in[],int n)   {
    if (n<=0)   return nullptr;
    int i=0;
    while (pre[0]!=in[i])   i++;
    bt* nw=new bt;
    nw->data=pre[0];
    nw->lc=preInBuildTree(pre+1,in,i);
    nw->rc=preInBuildTree(pre+i+1,in+i+1,n-i-1);
    return nw;
}

void postOrder(bt* root)    {
    if (root==nullptr)  return;
    postOrder(root->lc);
    postOrder(root->rc);
    if (cnt)   return;
    cout<<root->data<<endl;
    cnt++;
}
