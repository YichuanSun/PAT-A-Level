#include <iostream>
#include <vector>
using namespace std;
int e[210][210];
int main() {
    int nv, ne, m, ta, tb, k;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &ta, &tb);
        e[ta][tb] = e[tb][ta] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        vector<int> v(k);
        int hash[210] = {0}, isclique = 1, isMaximal = 1;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;
        }
        for (int j = 0; j < k; j++) {
            if (isclique == 0) break;
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0) continue;
        for (int j = 1; j <= nv; j++) {
            if (hash[j] == 0) {
                for (int l = 0; l < k; l++) {
                    if (e[v[l]][j] == 0) break;
                    if (l == k - 1) isMaximal = 0;
                }
            }
            if (isMaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (isMaximal == 1) printf("Yes\n");
    }
    return 0;
}

//#include <bits/stdc++.h>
//#define N 205
//using namespace std;
////int g[N][N];
//map<int,set<int> > ms;
//int main()  {
//    int ve,e,k;
//    scanf("%d%d",&ve,&e);
//    for (int i=0;i<e;i++)   {
//        int a,b;
//        scanf("%d%d",&a,&b);
//        ms[a].insert(b);
//        ms[b].insert(a);
//    }
//    scanf("%d",&k);
//    for (int i=0;i<k;i++)   {
//        int sz,spot=0;
//        vector<int> v(N);
//        scanf("%d",&sz);
//        for (int j=0;j<sz;j++)
//            scanf("%d",&v[j]);
//        for (int j=0;j<sz;j++)
//            for (int k=j+1;k<sz;k++)
//                if (ms[v[j]].count(v[k])!=1)   //没有该点
//                    {spot=1;break;}
//        if (spot)   {printf("Not a Clique\n");continue;}
//        for (int j=1;j<=ve;j++)  {
//            int cnt=0;
//            for (int k=0;k<sz;k++)  {
//                if (ms[j].count(v[k]))
//                    cnt++;
//                else break;
//            }
//            if (cnt==sz)    {spot=1;break;}
//        }
//        if (spot)   printf("Not Maximal\n");
//        else printf("Yes\n");
//    }
//    return 0;
//}
