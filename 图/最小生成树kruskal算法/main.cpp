#include <bits/stdc++.h>
using namespace std;
struct edge {int from,to,cost;};
bool cmp(const edge& e1,const edge& e2)    {
    return e1.cost<e2.cost;
}
edge es[MAX_E];
int V,E;
int kruskal()   {
    sort(es,es+MAX_E,cmp);
    init_union_find(V);
    int res=0;
    for (int i=0;i<E;i++)   {
        edge e=es[i];
        if (!same(e.from,e.to)) {
            unite_union_find(e.from,e.to);
            res+=e.cost;
        }
    }
    return res;
}
int main()  {
    return 0;
}
