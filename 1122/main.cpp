#include <bits/stdc++.h>
#define N 205
using namespace std;
int g[N][N],tv[N],cal[N];
int main()  {
    int n,m,k,p,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        cin>>p;
        int sp=0;
        for (int j=0;j<p;j++)   {
            cin>>tv[j];
            cal[tv[j]]++;
            if (j!=0&&j!=p-1&&cal[tv[j]]>1) sp=1;
        }
        if (p!=n+1) {
            cout<<"NO"<<endl;
            fill(tv,tv+N,0);
            fill(cal,cal+N,0);
            continue;
        }
        for (int j=1;j<=n;j++)  {
            if (cal[j]!=1)  {
                if (cal[j]==2&&j==tv[0]&&j==tv[p-1])   continue;
                else {sp=1;break;}
            }
        }
        for (int j=1;j<p;j++)   {
            if (sp==1)  break;
            if (g[tv[j-1]][tv[j]]!=1)  sp=1;
        }
        if (sp==1)  cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        fill(tv,tv+N,0);
        fill(cal,cal+N,0);
    }
    return 0;
}
