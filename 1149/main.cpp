#include <bits/stdc++.h>
#define N 100000
using namespace std;
vector<int> v[N];
int main()  {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=0;i<m;i++)   {
        int u;
        scanf("%d",&u);
        vector<int> vi;
        for (int j=0;j<u;j++)   {
            int tnum;
            scanf("%d",&tnum);
            vi.push_back(tnum);
        }
        int spot=0;
        for (int j=0;j<u;j++)   {
            for (int k=j+1;k<u;k++) {
                for (int l=0;l<(int)v[vi[j]].size();l++) {
                    if (v[vi[j]][l]==vi[k]) {
                        spot=1;
                        break;
                    }
                }
                if (spot)   break;
            }
            if (spot)   break;
        }
        if (spot)   printf("No\n");
        else    printf("Yes\n");
    }
    return 0;
}
