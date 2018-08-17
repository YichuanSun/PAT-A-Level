#include <bits/stdc++.h>
using namespace std;
int par[MAX_N]; //¸¸Ç×
int Rank[MAX_N];    //Ê÷µÄ¸ß¶È
void init_union_find()  {
    for (int i=0;i<n;i++)   {par[i]=i;Rank[i]=0;}
}
int find_union_find(int x)   {
    if (par[x]==x)  return par[x];
    else return par[x]=find_union_find(par[x]);
}
void unite_union_find(int x,int y)  {
    x=find_union_find(x);
    y=find_union_find(y);
    if (x==y)   return;
    if (Rank[x]<Rank[y])    par[x]=y;
    else    {
        par[y]=x;
        if (Rank[x]==Rank[y])   Rank[x]++;
    }
    bool same(int x,int y)  {
        return find_union_find(x)==find_union_find(y);
    }
}
int main()  {
    return 0;
}

