#include <bits/stdc++.h>
#define N 1005
using namespace std;
vector<int> vi[N],ans;		//vi是图的邻接表表示
int din[N];
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
        vector<int> tv(din,din+n+1);
        for (int i=0;i<n;i++)   {
            int t;
            scanf("%d",&t);
            if (tv[t]!=0)  flag=1;		//,入度非0，说明该序列不是拓扑排序
            for (int j=0;j<(int)vi[t].size();j++)
                tv[vi[t][j]]--;		//vi[t][j]意为节点t的第j个后继节点
        }
        if (flag)   ans.push_back(p);
    }
    printf("%d",ans[0]);
    for (int i=1;i<(int)ans.size();i++) printf(" %d",ans[i]);
    printf("\n");
    return 0;
}
