#include <bits/stdc++.h>
#define N 505
#define INF 100000005
using namespace std;
typedef pair<int,int> pii;
pii g[N][N];
int n,m,d[N],pred[N];
bool used[N];
void dijkstra(int be);
int main()  {
    int v1,v2,l,t,sp,be,en;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>v1>>v2>>sp>>l>>t;
        g[v1][v2]={l,t};
        if (sp==0)  g[v2][v1]={l,t};
    }
    cin>>be>>en;
    dijkstra(be);
    return 0;
}

void dijkstra(int be)   {
    fill(d,d+N,INF);
    fill(used,used+N,false);
    fill(pred,pred+N,-1);
    while (true)    {
        int v=-1;
        for (int u=0;u<n;u++)
            if (!used[u]&&(v==-1||d[u]<d[v]))   v=u;
        if (v==-1)  break;
        used[u]=true;
        for (int u=0;u<n;u++)
        if (d[u]<=d[v]+g[v][u].first)    {
            d[u]=d[v]+g[v][u].first;
            pred[u]=v;
        }
    }
}





