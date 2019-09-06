#include <bits/stdc++.h>
#define N 10005
using namespace std;
struct bst{
    int d;
    bst *lc,*rc;
};
typedef bst* pbst;
int a[N],le[N],sa[N];
void insertBuild(bst *&r,int t);

int leo(pbst p)    {       //≤„–Ú
    pbst q[N]={nullptr};
    int level=0,last=0;
    int frt=-1,re=-1;
    q[++re]=p;
    while (frt<re)  {
        pbst nw=q[++frt];
        le[frt]=level;
        if (nw==nullptr)    {sa[frt]=N;continue;}
        sa[frt]=nw->d;
        q[++re]=nw->lc;
        q[++re]=nw->rc;
        if (frt==last)   {
            level++;
            last=re;
        }
    }
    return frt;
}
int main()  {
    int n,mxl=-1,n1=0,n2=0;
    cin>>n;
    for (int i=0;i<n;i++)   cin>>a[i];
    bst* root=nullptr;
    for (int i=0;i<n;i++)
        insertBuild(root,a[i]);
    int fnode=leo(root);
    for (int i=0;i<=fnode;i++)   {
        //cout<<le[i]<<' '<<sa[i]<<endl;
        if (sa[i]==N)   continue;
        mxl=max(mxl,le[i]);
    }
    //cout<<"sdasd:\t"<<mxl<<endl;
    if (mxl==0) cout<<1<<endl;
    else    {
        for (int i=0;i<=fnode;i++)   {
            if (sa[i]==N)   continue;
            if (le[i]==mxl)   n1++;
            else if (le[i]==mxl-1)    n2++;
        }
        cout<<n1<<" + "<<n2<<" = "<<n1+n2<<endl;
    }
    return 0;
}

void insertBuild(pbst &r,int t) {
    if (r==nullptr) {
        r=new bst;
        r->d=t;
        r->lc=r->rc=nullptr;
    }
    else if (t<r->d) insertBuild(r->lc,t);
    else insertBuild(r->rc,t);
}
