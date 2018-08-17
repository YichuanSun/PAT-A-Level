#include <bits/stdc++.h>
#define MAX_V 1005
using namespace std;
bool edge[MAX_V][MAX_V];
bool used[MAX_V];
int dfs(int x);
int n,m,k;
int main()  {
    int n1,n2,cnt=0;
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<m;i++)   {
        scanf("%d %d",&n1,&n2);
        edge[n1][n2]=true;
        edge[n2][n1]=true;
    }
    for (int i=0;i<k;i++)   {
        cnt=0;
        fill(used,used+MAX_V,false);
        scanf("%d",&n1);
        used[n1]=true;
        for (int j=1;j<=n;j++)   {
            if (used[j]==false)   {
                dfs(j);
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}

int dfs(int x) {
    used[x]=true;
    for (int i=1;i<=n;i++)   {
        if (used[i]==false&&edge[x][i]==true)
            dfs(i);
    }
}

