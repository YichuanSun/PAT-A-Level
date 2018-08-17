#include <bits/stdc++.h>
#define MAX_V 505
#define INF 0x3f3f3f3f
using namespace std;
int dis[MAX_V][MAX_V],cost[MAX_V][MAX_V];
int d[MAX_V],pre[MAX_V],dollars[MAX_V];
bool used[MAX_V];
stack<int> st;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m,D,s,c1,c2;
    cin>>n>>m>>s>>D;
    fill(d,d+MAX_V,INF);    //起点到所有点距离设为INF
    fill(used,used+MAX_V,false);    //所有点都标记为未使用
    fill(dis[0],dis[0]+MAX_V*MAX_V,INF);    //所有边长度都标记为无穷大
    fill(cost[0],cost[0]+MAX_V*MAX_V,INF);
    fill(pre,pre+MAX_V,-1);
    fill(dollars,dollars+MAX_V,INF);
    d[s]=0;     //起点距离设为0
    dollars[s]=0;
    for (int i=0;i<m;i++)   {
        cin>>c1>>c2;
        cin>>dis[c1][c2]>>cost[c1][c2];
        dis[c2][c1]=dis[c1][c2];
        cost[c2][c1]=cost[c1][c2];
    }
    while (true)    {
        int v=-1;
        for (int u=0;u<n;u++)
            if (!used[u]&&(v==-1||d[u]<d[v]))   v=u;
        if (v==-1)  break;
        used[v]=true;
        for (int u=0;u<n;u++)   {
            if (d[u]>d[v]+dis[v][u])    {
                d[u]=d[v]+dis[v][u];
                pre[u]=v;
                dollars[u]=dollars[v]+cost[v][u];
            }
            else if (d[u]==d[v]+dis[v][u])   {
                if (dollars[u]>dollars[v]+cost[v][u])   {
                    dollars[u]=dollars[v]+cost[v][u];
                    pre[u]=v;
                }
            }
        }
    }
    int k=D;
    st.push(D);
    while (k!=s)    {
        st.push(pre[k]);
        k=pre[k];
    }
    while (!st.empty()) {
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<d[D]<<' ';
    cout<<dollars[D]<<endl;
    return 0;
}
