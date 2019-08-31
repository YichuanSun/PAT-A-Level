#include <bits/stdc++.h>
#define MAX_V 1005
#define INF 10000000
using namespace std;
struct edge {int to,cost;};
typedef pair<int,int> P;    //first路程长，second编号
int d[MAX_V];
int V;
vector<edge> G[MAX_V];      //邻接表表示每个顶点的边
void dijkstra(int s)  {
    priority_queue<int,vector<int>,greater<int> > que;
    fill(d,d+MAX_V,INF);
    d[s]=0;
    que.push(P(0,s));
    while (!que.empty())    {
        P p=que.top();que.pop();
        int v=p.second;
        if (d[v]<p.first)   continue;       //？
        for (int i=0;i<G[v].size();i++) {
            edge e=G[v][i];
            if (d[e.to]>d[v]+e.cost)    {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
