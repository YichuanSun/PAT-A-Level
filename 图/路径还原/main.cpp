#include <bits/stdc++.h>
#define MAX_V 1005
#define INF 10000005
using namespace std;
struct edge {int from,to,cost;};
int d[MAX_V];
bool used[MAX_V];
int prev[MAX_V];
int V;
int main()  {
    return 0;
}

int dijkstra(int s) {
    fill(d,d+V,INF);
    fill(used,used+V,false);
    fill(prev,prev+V,-1);
    while (true)    {
        int v=-1;
        for (int u=0;u<V;u++)   if (!used[u]&&(v==-1||d[u]<d[v]))  v=u;
        used[v]=true;
        for (int u=0;u<V;u++)   {
            if (d[u]>d[v]+cost[v][u])   {
                d[u]=d[v]+cost[v][u];
                prev[u]=v;
            }
        }
    }
}
