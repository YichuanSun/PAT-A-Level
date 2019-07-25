#include<bits/stdc++.h>
#define N 10005
using namespace std;
vector<int> v[N];
int co[N];
int main()  {
    int n,m,k,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        for (int j=0;j<n;j++)   scanf("%d",&co[j]); //此处最初j误写了i,找了好久才发现
        int cnt=-1;
        set<int> si;
        for (int p=0;p<n;p++)   {   //对所有邻接表
            si.insert(co[p]);
            for (int y=0;y<(int)v[p].size();y++)    {
                if (co[v[p][y]]==co[p]) {cnt=0;break;}
                si.insert(co[v[p][y]]);
            }
            if (cnt==0) break;
        }
        if (cnt==0) printf("No\n");
        else    printf("%d-coloring\n",(int)si.size());
    }
    return 0;
}
