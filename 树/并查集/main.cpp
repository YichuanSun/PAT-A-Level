#include <bits/stdc++.h>
#define MAX_N 1005
using namespace std;
int par[MAX_N]; //the father of i
int Rank[MAX_N];    //the hight of tree i
void init_union_find(int n)  {       //initial find_union set
    for (int i=0;i<n;i++)   {par[i]=i;Rank[i]=0;}
}
int find_union_find(int x)   {      //return the belonging node of x
    while (par[x]!=x)   {
        par[x]=par[par[x]];     //maybe can make the path compression
        printf("%d ",par[x]);
    }
    cout<<endl;
    return par[x];
}
void unite_union_find(int x,int y)  {
    x=find_union_find(x);
    y=find_union_find(y);
    printf("%d %d\n",x,y);
    if (x==y)   return;
    if (Rank[x]<Rank[y])    par[x]=y;
    else    {
        par[y]=x;
        if (Rank[x]==Rank[y])   Rank[x]++;
    }
    //printf("OK\n");
}
bool same(int x,int y)  {
    return find_union_find(x)==find_union_find(y);
}
int main()  {
    int n;
    scanf("%d",&n);
    init_union_find(n);
    unite_union_find(1,2);
    unite_union_find(2,4);
//    for (int i=0;i<n;i++)   printf("%d%c",par[i],i==n-1?'\n':' ');
//    printf("%d\n",find_union_find(4));
//    for (int i=0;i<n;i++)   printf("%d%c",par[i],i==n-1?'\n':' ');
    return 0;
}
