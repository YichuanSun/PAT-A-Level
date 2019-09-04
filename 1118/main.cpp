//并查集用的很生硬啊。。。
#include <bits/stdc++.h>
#define N 10005
using namespace std;
int par[N],h[N],st[N],bd[N],n;
void uInit();
int uFind(int k);
void uUnite(int a,int b);
bool uSame(int a,int b);
set<int> si;
int main()  {
    int tk,p,bdn=1;
    cin>>n;
    uInit();
    for (int i=1;i<=n;i++)   {
        cin>>tk;
        int sp=0,nw;
        for (int j=0;j<tk;j++)  {
            cin>>st[j];
            bd[st[j]]=1;
            if (uFind(st[j])!=st[j])    {
                sp=1;
                nw=uFind(st[j]);
            }
            if (sp==1)  uUnite(nw,st[j]);
            else if (j!=0)   uUnite(st[j-1],st[j]);
            si.insert(st[j]);
        }
    }
    while (bd[bdn])  bdn++;
    cout<<si.size()<<' '<<bdn-1<<endl;
    cin>>tk;
    for (int i=0;i<tk;i++)  {
        cin>>p>>bdn;
        if (uSame(p,bdn))   cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

void uInit() {
    for (int i=0;i<=n;i++)  {
        par[i]=i;
        h[i]=0;
    }
}

int uFind(int k) {
    if (par[k]==k)   return par[k];
    return par[k]=uFind(par[k]);
}

void uUnite(int a,int b)    {
    a=uFind(a);
    b=uFind(b);
    if (a==b)   return;
    if (h[a]<h[b])  par[a]=b;
    else {
        par[b]=a;
        if (h[a]==h[b])   h[a]++;
    }
}

bool uSame(int a,int b) {return uFind(a)==uFind(b);}
