#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int MAX_N=1005;
typedef vector<int> veci;
veci path[MAX_N];
struct node{
    int num;
    int wi;
    int nex;
    veci child;
}ns[N];
int cnt=0;
void dfs(int y,int s);
bool cmp(veci a,veci b)  {
    unsigned i=0;
    for (;i<a.size()&&i<b.size();i++)   {
        if (a[i]!=b[i]) return a[i]>b[i];
    }
    return true;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,s,t,tn,tc;
    cin>>n>>m>>s;
    for (int i=0;i<n;i++)   {
        cin>>t;
        ns[i].num=i;
        ns[i].wi=t;
    }
    for (int i=0;i<m;i++)   {
        cin>>t;
        cin>>tn;
        for (int j=0;j<tn;j++)  {
            cin>>tc;
            ns[t].child.push_back(tc);
        }
    }
    dfs(0,s);
    sort(path,path+cnt,cmp);
    for (int i=0;i<cnt;i++)    {
        cout<<path[i][0];
        for (unsigned j=1;j<path[i].size();j++) {
            cout<<' '<<path[i][j];
        }
        cout<<endl;
    }
    return 0;
}

void dfs(int y,int s) {
    if (ns[y].wi>s)    return;
    else if (ns[y].wi<s)   {
        for (unsigned i=0;i<ns[y].child.size();i++) {
            ns[y].nex=(ns[y].child)[i];
            dfs((ns[y].child)[i],s-ns[y].wi);
        }
    }
    else    {
        if (ns[y].child.size()!=0)  {
            return;
        }
        else    {
            node tnode=ns[0];
            path[cnt].push_back(tnode.wi);
            tnode=ns[tnode.nex];
            while (tnode.nex!=0)    {
                path[cnt].push_back(tnode.wi);
                tnode=ns[tnode.nex];
            }
            path[cnt].push_back(tnode.wi);
            cnt++;
            return;
        }
    }
}
