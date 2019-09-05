#include <bits/stdc++.h>
#define N 10005
using namespace std;
struct bst{
    int d;
    bst *lc,*rc;
};
int a[N];
void insertBuild(bst *&r,int t);
void prt(bst* p);
void ino(bst* p)    {
    if (p==nullptr) return;
    prt(p->lc);
    cout<<p->d<<' ';
    prt(p->rc);
}
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   cin>>a[i];
    bst* root=nullptr;
    for (int i=0;i<n;i++)   {
        insertBuild(root,a[i]);
    }
    prt(root);
    cout<<endl;
    ino(root);
    return 0;
}

void prt(bst* p)    {
    if (p==nullptr) return;
    cout<<p->d<<' ';
    prt(p->lc);
    prt(p->rc);
}

void insertBuild(bst *&r,int t) {
    if (r==nullptr) {
        bst* nw=new bst;
        nw->d=t;
        nw->lc=nw->rc=nullptr;
        r=nw;
    }
    else if (t<r->d) insertBuild(r->lc,t);
    else insertBuild(r->rc,t);
}

