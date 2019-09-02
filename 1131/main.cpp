#include <bits/stdc++.h>
#define N 105
#define MN 10003
using namespace std;
int sz[N];
int g[MN][MN],used[MN],pred[MN];
vector<int> v[N],des[MN],adjv[MN];   //des记录每个站属于的线路
void udg(int be,int en);
void dijkstra(int be,int en);
void print(int be,int en);
int main()  {
    int n,k,be,en;
    cin>>n;
    for (int i=1;i<=n;i++)   {
        cin>>sz[i];
        for (int j=0;j<sz[i];j++)   {
            cin>>k;
            v[i].push_back(k);
            des[k].push_back(i);
            if (j!=0)   {
                g[v[i][j-1]][k]=i;
                g[k][v[i][j-1]]=i;
            }
            if (j!=0)   {
                adjv[v[i][j-1]].push_back(k);
                adjv[k].push_back(v[i][j-1]);
            }
        }
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        cin>>be>>en;
        fill(used,used+MN,0);
        udg(be,en);
        cout<<"OK"<<endl;
        //dijkstra(be,en);
        print(be,en);
    }
    return 0;
}
void udg(int be,int en) {   //最开始我想用无向图的广搜，发现我不会这种路径还原
    queue<int> q;
    stack<int> s;
    pred[be]=-1;
    q.push(be);
    while (!q.empty())  {
        int nw=q.front();
        used[nw]=1;
        if (nw==en) return;
        q.pop();
        for (int i=0;i<(int)adjv[nw].size();i++) {
            if (!used[adjv[nw][i]]) {
                q.push(adjv[nw][i]);
                pred[adjv[nw][i]]=nw;
            }
        }
    }
}
void dijkstra(int be,int en)    {

}
void print(int be,int en)  {
    vector<int> ans;
    for (;en!=-1;en=pred[en])   ans.push_back(en);
    reverse(ans.begin(),ans.end());
    int pre=be,nw;
    for (int i=1;i<(int)ans.size();i++) {
        if (i==1)   {
            nw=g[pre][ans[i]];
            pre=ans[i];
        }
        if (nw!=g[pre][ans[i]]) {
            printf("Take Line#%d from %d to %d.\n",g[pre][ans[i]],pre,ans[i]);
        }
    }
}
