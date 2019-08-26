#include <bits/stdc++.h>
#define N 10002
using namespace std;
int g[N][N],v[N];
vector<int> vi[N];
typedef set<pair<int,int> > sp;
int main()  {
    int n,m,a,b,k,d;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        cin>>d;
        sp nsp;
        for (int j=0;j<d;j++)   {
            cin>>v[i];
            for (int w=0;w<(int)vi[v[i]].size();w++)    {
                nsp.insert({v[i],vi[v[i]][w]});
                nsp.insert({vi[v[i]][w],v[i]});
            }
        }
        if ((int)nsp.size()==m*2)   cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

////set版，后两个用例超时
//#include <bits/stdc++.h>
//#define N 10002
//using namespace std;
//int g[N][N],v[N];
//vector<int> vi[N];
//typedef set<pair<int,int> > sp;
//int main()  {
//    int n,m,a,b,k,d;
//    cin>>n>>m;
//    for (int i=0;i<m;i++)   {
//        cin>>a>>b;
//        g[a][b]=g[b][a]=1;
//        vi[a].push_back(b);
//        vi[b].push_back(a);
//    }
//    cin>>k;
//    for (int i=0;i<k;i++)   {
//        cin>>d;
//        sp nsp;
//        for (int j=0;j<d;j++)   {
//            cin>>v[i];
//            for (int w=0;w<(int)vi[v[i]].size();w++)    {
//                nsp.insert({v[i],vi[v[i]][w]});
//                nsp.insert({vi[v[i]][w],v[i]});
//            }
//        }
//        if ((int)nsp.size()==m*2)   cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//    return 0;
//}
