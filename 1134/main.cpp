////这个对了
//#include <bits/stdc++.h>
//#define N 10002
//using namespace std;
//vector<int> e[N];
//int main()  {
//    int n,m,a,b,k,d;
//    cin>>n>>m;
//    for (int i=0;i<m;i++)   {
//        cin>>a>>b;
//        e[a].push_back(i);
//        e[b].push_back(i);
//    }
//    cin>>k;
//    for (int i=0;i<k;i++)   {
//        cin>>d;
//        int r,cnt=0,ha[N]={0};  //最后一个bug：数组未初始化
//        for (int j=0;j<d;j++)  {
//            cin>>r;
//            for (int p=0;p<(int)e[r].size();p++)    {
//                ha[e[r][p]]=1;
//            }
//        }
//        for (int p=0;p<m;p++)
//            if (ha[p]==1)   cnt++;
//        if (cnt==m) cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//    return 0;
//}

//用了公式，还是超时,因为有一个n^2操作？
//#include <bits/stdc++.h>
//#define N 10002
//using namespace std;
//int g[N][N],v[N];
//vector<int> vi[N];
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
//        int sum=0,sub=0;
//        for (int j=0;j<d;j++)   {
//            cin>>v[j];
//            sum+=vi[v[j]].size();
//        }
//        for (int j=0;j<d;j++)   {   //n^2
//            for (int u=j+1;u<d;u++) {
//                if (g[v[j]][v[u]]==1)
//                    sub++;
//            }
//        }
//        if ((sum-sub)==m) cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//    return 0;
//}

//set版，后两个用例超时
#include <bits/stdc++.h>
#define N 10002
using namespace std;
int g[N][N],v[N];
vector<int> vi[N];
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
        unordered_set<pair<int,int> > nsp;
        for (int j=0;j<d;j++)   {
            cin>>v[i];
            for (int w=0;w<(int)vi[v[i]].size();w++)    {
                nsp.insert({v[i],vi[v[i]][w]});
                nsp.insert({vi[v[i]][w],v[i]});
            }
        }
        //if ((int)nsp.size()==m*2)   cout<<"Yes"<<endl;
        //else cout<<"No"<<endl;
    }
    return 0;
}
