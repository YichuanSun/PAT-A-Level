#include <bits/stdc++.h>
#define N 505
using namespace std;
int odg[N];
bool usd[N];
vector<int> g[N];
void dfs(int p);
int main()  {
    int n,m,a,b,odd=0;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        odg[a]++;odg[b]++;
    }
    for (int i=1;i<=n;i++)  {
        int dg=odg[i];
        printf("%d%c",dg,i==n?'\n':' ');
        if ((dg&1)==1)  odd++;
    }
    dfs(1);
    for (int i=1;i<=n;i++)   {
        if (!usd[i])    {
            cout<<"Non-Eulerian"<<endl;
            return 0;
        }
    }
    if (odd==0) cout<<"Eulerian"<<endl;
    else if (odd==2)    cout<<"Semi-Eulerian"<<endl;
    else cout<<"Non-Eulerian"<<endl;
    return 0;
}

void dfs(int p) {
    if (usd[p]) return;
    usd[p]=true;
    for (int i=0;i<(int)g[p].size();i++)
        dfs(g[p][i]);
}

