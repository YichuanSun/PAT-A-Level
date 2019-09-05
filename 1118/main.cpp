#include <bits/stdc++.h>
#define N 10005
using namespace std;

int par[N],n,tre[N];
bool ex[N];

void uInit();
int uFind(int k);
void uUnite(int a,int b);
bool uSame(int a,int b);
int main()  {
    int tk,bnum=-1,tnum=0,a,b;
    scanf("%d",&n);
    uInit();
    for (int i=1;i<=n;i++)   {
        scanf("%d",&tk);
        for (int j=0;j<tk;j++)  {
            cin>>a;
            if (j==0)   b=a;
            uUnite(b,a);
            ex[a]=1;
            bnum=max(bnum,a);
        }
    }
    for (int i=1;i<=bnum;i++)   {
        if (ex[i])  {
            int root=uFind(i);
            if (tre[root]==0)   tnum++;
            tre[root]++;
        }
    }
    scanf("%d",&tk);
    printf("%d %d\n",tnum,bnum);
    for (int i=0;i<tk;i++)  {
        scanf("%d%d",&a,&b);
        printf("%s",uFind(a)==uFind(b)?"Yes\n":"No\n");
    }
    return 0;
}

void uInit() {for (int i=0;i<N;i++)  par[i]=i;}
int uFind(int k) {
    int a=k;
    while (k!=par[k])    k=par[k];
    while (a!=par[a])    {int z=a;a=par[a];par[z]=k;}
    return k;
}

void uUnite(int a,int b)    {
    a=uFind(a);
    b=uFind(b);
    if (a!=b)   par[a]=b;
}

bool uSame(int a,int b) {return uFind(a)==uFind(b);}

//下面这段是以前经常用的并查集算法，发现其中几块
//效率不高，实现复杂，没必要
//#include <bits/stdc++.h>
//#define N 10005
//using namespace std;
//
//int par[N],h[N],n,tre[N];
//bool ex[N];
//set<int> si;
//
//void uInit();
//int uFind(int k);
//void uUnite(int a,int b);
//int main()  {
//    int tk,bnum=-1,tnum=0,a,b;
//    scanf("%d",&n);
//    uInit();
//    for (int i=1;i<=n;i++)   {
//        scanf("%d",&tk);
//        for (int j=0;j<tk;j++)  {
//            cin>>a;
//            if (j==0)   b=a;
//            uUnite(b,a);
//            ex[a]=1;
//            bnum=max(bnum,a);
//        }
//    }
//    for (int i=1;i<=bnum;i++)   {
//        int root=uFind(i);
//        if (tre[root]==0)   tnum++;
//        tre[root]++;
//    }
//    scanf("%d",&tk);
//    cout<<tnum<<' '<<bnum<<endl;
//    for (int i=0;i<tk;i++)  {
//        scanf("%d%d",&a,&b);
//        printf("%s",uFind(a)==uFind(b)?"Yes\n":"No\n");
//    }
//    return 0;
//}
//
//void uInit() {
//    for (int i=0;i<N;i++)  {
//        par[i]=i;
//        h[i]=0;
//    }
//}
//
//int uFind(int k) {
//    int a=k;
//    while (k!=par[k])    k=par[k];
//    while (a!=par[a])    {int z=a;a=par[a];par[z]=k;}
//    return k;
////    if (par[k]==k)   return par[k];
////    return par[k]=uFind(par[k]);
//}
//
//void uUnite(int a,int b)    {
//    a=uFind(a);
//    b=uFind(b);
//    if (a==b)   return;
//    if (h[a]<h[b])  par[a]=b;
//    else {
//        par[b]=a;
//        if (h[a]==h[b])   h[a]++;
//    }
//}
