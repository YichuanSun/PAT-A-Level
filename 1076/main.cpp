#include <bits/stdc++.h>
#define N 1005
using namespace std;
int n,l;
bool g[N][N],used[N];
queue<int> que;
int bfs(int tn);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    int tn,tmp,k;
    for (int i=1;i<=n;i++)  {
        cin>>tn;
        for (int j=0;j<tn;j++)  {
            cin>>tmp;
            g[tmp][i]=true;
        }
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        cin>>tn;
        int ans=bfs(tn);
        cout<<ans<<endl;
        while (!que.empty())    que.pop();
    }
    return 0;
}

int bfs(int tn)    {
    fill(used,used+N,false);
    int cnt=0,ans=0;
    int cot[7];
    fill(cot,cot+7,0);
    que.push(tn);
    used[tn]=true;
    cot[0]=1;
    while (!que.empty()&&cnt<l)    {
        int tt=que.front();
        que.pop();
        cot[cnt]--;
        for (int i=1;i<=n;i++)  {
            if (i==tn)  continue;
            if (used[i])    continue;
            if (!g[tt][i])  continue;
            que.push(i);
            used[i]=true;
            cot[cnt+1]++;
            ans++;
        }
        if (cot[cnt]==0)    cnt++;
    }
    return ans;
}
