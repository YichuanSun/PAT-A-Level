#include<bits/stdc++.h>
#define N 10005
using namespace std;
vector<int> v[N];
int co[N];
int main()  {
    int n,m,k,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        for (int j=0;j<n;j++)   cin>>co[i];
        int ans=0;
        for (int p=0;p<n;p++)   {   //对所有邻接表
            set<int> si;
            si.insert(co[p]);
            for (int m=0;m<(int)v[p].size();m++)    {
                if (co[v[p][m]]==co[p]) {ans=0;break;}
                si.insert(co[v[p][m]]);
            }
            ans=max(ans,(int)si.size());
        }
        if (ans==0) printf("No\n");
        else printf("%d-coloring\n",ans);
    }
    return 0;
}
