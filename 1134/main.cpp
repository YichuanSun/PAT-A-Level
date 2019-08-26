#include <bits/stdc++.h>
#define N 10002
using namespace std;
int g[N][N],v[N];
int main()  {
    int n,m,a,b,k,d;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
    }
    for (int i=0;i<n;i++)   {
        for (int j=0;j<n;j++)
            cout<<g[i][j]<<' ';
        cout<<endl;
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        cin>>d;
        for (int j=0;j<d;j++)   cin>>v[j];
        int fl=0;
        for (int j=0;j<d;j++)   {
            int spot=0;
            for (int m=j+1;m<d;m++)
                if (g[v[j]][v[m]]==1)
                    spot++;
                else cout<<v[j]<<' '<<v[m]<<endl;
            if (spot==0)    {
                cout<<"ok"<<endl;
                fl=1;break;
            }
        }
        if (fl) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}

//#include <bits/stdc++.h>
//#define N 1005
//using namespace std;
//int par[N],h[N],v[N];
//void Init(int n);
//int Find(int p);
//void Union(int a,int b);
//bool Same(int a,int b);
//int main()  {
//    int n,m,a,b,k,d;
//    cin>>n>>m;
//    for (int i=0;i<m;i++)   {
//        cin>>a>>b;
//        Union(a,b);
//    }
//    cin>>k;
//    for (int i=0;i<k;i++)   {
//        cin>>d;
//        set<int> si;
//        for (int j=0;j<d;j++)   {
//            cin>>v[j];
//            si.insert(Find(v[j]));
//        }
//        if (si.size()==1)   cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//    return 0;
//}
//
//
//void Init(int n) {
//    for (int i=0;i<=n;i++)  {
//        par[i]=i;
//        h[i]=0;
//    }
//}
//int Find(int p)   {
//    if (par[p]==p)  return p;
//    return par[p]=Find(par[p]);
//}
//void Union(int a,int b) {
//    a=Find(a);
//    b=Find(b);
//    if (a==b)   return;
//    else if (h[a]<h[b]) par[a]=b;
//    else if (h[b]<h[a]) par[b]=a;
//    else {par[b]=a;h[a]++;}
//}
//bool Same(int a,int b)  {return Find(a)==Find(b);}
