#include <bits/stdc++.h>
#define INF 10000000
#define MAX_V 1005
using namespace std;
int d[MAX_V];
int cost[MAX_V][MAX_V];
bool used[MAX_V];
int V;
void dijkstra(int s)    {
    fill(d,d+MAX_V,INF);
    fill(used,used+MAX_V,false);
    d[s]=0;
    while (true)    {
        int v=-1;
        for (int u=0;u<V;u++)
            if (!used[u]&&(v==-1||d[u]<d[v]))   v=u;
        if (v==-1)  break;
        used[v]=true;
        for (int u=0;u<V;u++)
            d[u]=min(d[u],d[v]+cost[v][u]);
    }
}


int main()  {
    return 0;
}
