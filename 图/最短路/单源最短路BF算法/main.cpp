#include <bits/stdc++.h>
#define INF 100000
using namespace std;
struct edge{int from,to,cost;};
edge es[MAX_E];
int d[MAX_V];
int V,E;
void shortest_path(int s)   {
    for (int i=0;i<V;i++)   d[i]=INF;
    d[s]=0;
    while (true)    {
        bool update=false;
        for (int i=0;i<E;i++)   {
            edge e=es[i];
            if (d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        if (!update)    break;
    }
}
//检查是否有负圈,如果返回true就有负圈
bool find_negative_loop()   {
    memset(d,0,sizeof(d));
    for (int i=0;i<V;i++)   {
        for (int j=0;j<E;j++)   {
            edge e=es[j];
            if (d[e.to]>d[e.from]+e.cost)   {
                d[e.to]=d[e.from]+e.cost;
                if (i==V-1) return true;
            }
        }
    }
    return false;
}
int main()  {

    return 0;
}


