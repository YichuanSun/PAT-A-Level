#include <bits/stdc++.h>
#define N 100000
using namespace std;

bool is_Prime(int n)    {
    if (n==1||n==0) return false;
    for (int i=2;i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}
int ha[N];
int main()  {
    int s,n,m,ans=0;
    scanf("%d%d%d",&s,&n,&m);
    while (!is_Prime(s))    s++;
    for (int i=0;i<n;i++)  {
        int flag=0,t=0;
        scanf("%d",&t);
        for (int j=0;j<=s;j++)  {
            int key=(t+j*j)%s;
            if (ha[key]==0)   {
                ha[key]=t;
                flag=1;
                break;
            }
        }
        if (!flag)  printf("%d cannot be inserted.\n",t);
    }
    for (int i=0;i<m;i++)   {
        int t=0;
        scanf("%d",&t);
        for (int j=0;j<=s;j++)  {
            ans++;
            int tk=(t+j*j)%s;
            if (ha[tk]==t||ha[tk]==0)   break;
        }
    }
    printf("%.1f\n",1.0*ans/m);
    return 0;
}





