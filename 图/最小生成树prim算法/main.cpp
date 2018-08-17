#include <bits/stdc++.h>
#define MAX_V   1005
using namespace std;
int mincost[MAX_V];
int cost[MAX_V][MAX_V];
bool used[MAX_V];
int V,E;

int main()  {
    return 0;
}

int prim()  {
    int res=0;
    fill(mincost,mincost+MAX_V,INF);
    fill(used,used+MAX_V,false);
    mincost[0]=0;
    while (true)    {
        int v=-1;
        for (int u=0;u<V;u++)
            if (!used[u]&&(v==-1||mincost[u]<mincost[v]))   v=u;
        if (v==-1)  break;
        used[v]=true;
        res+=mincost[v];
        for (int u=0;u<V;u++)   mincost[u]=min(mincost[u],cost[v][u]);
    }
    return res;
}





