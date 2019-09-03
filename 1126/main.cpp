#include <bits/stdc++.h>
#define N 505
using namespace std;
int g[N][N];
vector<int> v[N];
int idg[N],odg[N];
int main()  {
    int n,m,a,b,odd=0;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a][b]=1;
        odg[a]++;
        idg[b]++;
    }
    for (int i=1;i<=n;i++)  {
        int dg=odg[i]+idg[i];
        printf("%d%c",dg,i==n?'\n':' ');
        if ((dg&1)==1)  odd++;
    }
    if (odd==0) cout<<"Eulerian"<<endl;
    else if (odd==2)    cout<<"Semi-Eulerian"<<endl;
    else cout<<"Non-Eulerian"<<endl;
    return 0;
}
