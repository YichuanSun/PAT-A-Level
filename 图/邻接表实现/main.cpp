#include <bits/stdc++.h>
using namespace std;

//邻接表样例一
vector<int> G[MAX_V];
int main()  {
    int V,E;
    scanf("%d %d",&V,&E);
    for (int i=0;i<E;i++)   {
        int s,t;
        scanf("%d %d",&s,&t);
        G[s].push_back(t);
    }
    return 0;
}

//邻接表样例二
struct vertex   {
    vector<vertex*> edge;
};
vertex G[MAX_V];
int main()  {
    int V,E;
    scanf("%d %d",&V,&E);
    for (int i=0;i<E;i++)   {
        int s,t;
        scanf("%d %d",&V,&E);
        G[s].edge.push_back(&G[t]);
    }
    return 0;
}
