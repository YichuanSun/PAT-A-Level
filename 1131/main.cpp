#include <bits/stdc++.h>
#define N 105
#define MN 10003
using namespace std;
int sz[N];
int g[MN][MN],used[MN],pred[MN];
vector<int> v[N],adjv[MN];
void udg(int be,int en);
void print(int be,int en);
int main()  {
    int n,k,be,en;
    cin>>n;
    for (int i=1;i<=n;i++)   {
        cin>>sz[i];
        for (int j=0;j<sz[i];j++)   {
            cin>>k;
            v[i].push_back(k);
            if (j!=0)   {
                g[v[i][j-1]][k]=i;
                g[k][v[i][j-1]]=i;
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
        print(be,en);
    }
    return 0;
}
void udg(int be,int en) {
    queue<int> q;
    stack<int> s;
    pred[be]=-1;
    q.push(be);
    while (!q.empty())  {
        int nw=q.front();
        q.pop();
        if (used[nw])   continue;
        used[nw]=1;
        //cout<<nw<<endl;
        //system("pause");;
        if (nw==en) return;
        for (int i=0;i<(int)adjv[nw].size();i++) {
            if (!used[adjv[nw][i]]) {
                q.push(adjv[nw][i]);
                pred[adjv[nw][i]]=nw;
            }
        }
    }
}
void print(int be,int en)  {
    vector<int> ans;
    for (;en!=-1;en=pred[en])   ans.push_back(en);
    reverse(ans.begin(),ans.end());
    int siz=(int)ans.size();
    printf("%d\n",siz-1);
    int rd,st=be;    //记录当前的线路rd,前驱pr,这条线路上的起点st
    for (int i=0;i<(int)siz;i++)    {
        if (i==0)   {rd=g[be][ans[1]];}
        if (i<siz-1&&rd!=g[ans[i]][ans[i+1]]) {
            printf("Take Line#%d from %d to %d.\n",rd,st,ans[i]);
            st=ans[i];
            rd=g[ans[i]][ans[i+1]];
        }
        if (i==siz-1)   printf("Take Line#%d from %d to %d.\n",rd,st,ans[i]);
    }
}
