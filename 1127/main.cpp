#include <bits/stdc++.h>
#define N 105
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
int post[N],in[N],cnt,c,n;
vector<int> v[N];
queue<bt*> qb;
bt* postInbuildTree(int post[],int in[],int n)  {
    if (n<=0)   return nullptr;
    int i=0;
    while (post[n-1]!=in[i]) i++;
    bt* nw=new bt;
    nw->data=in[i];
    nw->lc=postInbuildTree(post,in,i);
    nw->rc=postInbuildTree(post+i,in+i+1,n-i-1);
    return nw;
}
void zigzagTraversal(bt* root)  {
    if (root==nullptr) return;
    bt *last=root,*T=root,*frt=nullptr;
    qb.push(T);
    while (!qb.empty()) {
        frt=qb.front();qb.pop();
        v[cnt].push_back(frt->data);
        if (frt->lc)  qb.push(frt->lc);
        if (frt->rc)  qb.push(frt->rc);
        if (frt==last)  {
            if (!(cnt&1))   reverse(v[cnt].begin(),v[cnt].end());
            last=qb.back();
            for (int i=0;i<(int)v[cnt].size();i++,c++)
                printf("%d%c",v[cnt][i],c==n-1?'\n':' ');
            cnt++;
        }
    }
}
int main()  {
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
    bt* root=postInbuildTree(post,in,n);
    zigzagTraversal(root);
    return 0;
}
