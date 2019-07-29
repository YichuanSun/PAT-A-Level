#include <bits/stdc++.h>
#define N 1005
using namespace std;
vector<int> vi[N],ans;
int g[N][N],din[N];
int main(){
    int n,m,k;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)   {
        int a,b;
        scanf("%d%d",&a,&b);
        vi[a].push_back(b);
        din[b]++;
    }
    scanf("%d",&k);
    for (int p=0;p<k;p++) {
        int flag=0;
        for (int i=0;i<n;i++)   {
            int t;
            scanf("%d",&t);
            if (din[t]!=0)  flag=1;
            for (int j=0;j<(int)vi[t].size();j++)
                din[vi[t][j]]--;
        }
        if (flag)   ans.push_back(p);
    }
    printf("%d",ans[0]);
    for (int i=1;i<(int)ans.size();i++) printf(" %d",ans[i]);
    printf("\n");
    return 0;
}
