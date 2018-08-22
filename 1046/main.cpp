#include <bits/stdc++.h>
#define N 100005
using namespace std;
int dis[N];
int main()  {
    int n,m;
    dis[0]=0;
    dis[1]=0;
    cin>>n;
    for (int i=2;i<=n+1;i++)   {
        cin>>dis[i];
        dis[i]+=dis[i-1];
    }
    //for (int i=1;i<=n+1;i++)  cout<<dis[i]<<endl;
    int s1,s2;
    cin>>m;
    for (int i=0;i<m;i++)   {
        cin>>s1>>s2;
        int di=abs(dis[s2]-dis[s1]);
        cout<<min(di,dis[n+1]-di)<<endl;
    }
    return 0;
}
