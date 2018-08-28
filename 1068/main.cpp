#include <bits/stdc++.h>
using namespace std;
int pre[10005],n,m,cnt;
vector<int> ans[100];
void dfs(int *a,int b,int m,int d);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int *a=new int[n];
    cin>>n>>m;
    for (int i=0;i<n;i++)   cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++)   dfs(a,i,m,i);
    return 0;
}

void dfs(int *a,int b,int m,int d) {
    if (m<0)    return;
    if (m==0)   {
        while (b!=d)    {
            ans[cnt].push_back(a[b]);
            b=pre[b];
        }
        ans[cnt].push_back(a[d]);
        cnt++;
        return;
    }
    for (int i=b;i<n;i++) {
        if (m-a[i]>=0)  {
            pre[i]=b;
            dfs(a,i,m-a[i],d);
        }
    }
}


