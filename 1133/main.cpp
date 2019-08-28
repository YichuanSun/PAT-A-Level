#include <iostream>
#define N 100005
using namespace std;
class node{
    public:
        int data,next;
        node() : data(0),next(0) {}
        node(int a,int b) : data(a),next(b){}
};
node tot[N],sa[N],ne[N],co[N],ord[N];
int main(){
    int be,k,n,ad,d,nx;
    int neb=-1,cob=-1,ordb=-1;
    cin>>be>>n>>k;
    int nw=0,cw=0,ow=0,pr=be;
    for (int i=0;i<n;i++)   {
        cin>>ad>>d>>nx;
        tot[ad]=node(d,nx);
    }
    for (;pr!=-1;pr=tot[pr].next)  {
        int ad=pr,d=tot[pr].data,nx=tot[pr].next;
        if (d<0)    {
            ne[ad]=node(d,nx);
            if (neb==-1)    {nw=neb=ad;}
            else {ne[nw].next=ad;nw=ad;}
        }
        else if (d>=0&&d<=k)    {
            co[ad]=node(d,nx);
            if (cob==-1)    cw=cob=ad;
            else {co[cw].next=ad;cw=ad;}
        }
        else{
            ord[ad]=node(d,nx);
            if (ordb==-1)   ow=ordb=ad;
            else {ord[ow].next=ad;ow=ad;}
        }
    }
    ne[nw].next=cob;
    co[cw].next=ordb;
    ord[ow].next=-1;
    for (int ptr=neb;ptr!=cob;ptr=ne[ptr].next)
        printf("%05d %d %05d\n",ptr,ne[ptr].data,ne[ptr].next);
    for (int ptr=cob;ptr!=ordb;ptr=co[ptr].next)
        printf("%05d %d %05d\n",ptr,co[ptr].data,co[ptr].next);
    for (int ptr=ordb;ptr!=-1;ptr=ord[ptr].next)    {
        if (ord[ptr].next!=-1)
            printf("%05d %d %05d\n",ptr,ord[ptr].data,ord[ptr].next);
        else
            printf("%05d %d %d\n",ptr,ord[ptr].data,ord[ptr].next);
    }
    return 0;
}