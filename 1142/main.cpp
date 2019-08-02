#include <bits/stdc++.h>
#define N 205
using namespace std;
//int g[N][N];
map<int,set<int> > ms;
int main()  {
    int ve,e,k;
    scanf("%d%d",&ve,&e);
    for (int i=0;i<e;i++)   {
        int a,b;
        scanf("%d%d",&a,&b);
        ms[a].insert(b);
        ms[b].insert(a);
    }
    scanf("%d",&k);
    for (int i=0;i<k;i++)   {
        int sz,spot=0;
        vector<int> v(N);
        scanf("%d",&sz);
        for (int j=0;j<sz;j++)
            scanf("%d",&v[j]);
        for (int j=0;j<sz;j++)
            for (int k=j+1;k<sz;k++)
                if (ms[v[j]].count(v[k])!=1)   //没有该点
                    {spot=1;break;}
        if (spot)   {printf("Not a Clique\n");continue;}
        for (int j=1;j<=ve;j++)  {
            int cnt=0;
            for (int k=0;k<sz;k++)  {
                if (ms[j].count(v[k]))
                    cnt++;
                else break;
            }
            if (cnt==sz)    {spot=1;break;}
        }
        if (spot)   printf("Not Maximal\n");
        else printf("Yes\n");
    }
    return 0;
}
