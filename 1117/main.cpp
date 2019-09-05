#include <bits/stdc++.h>
#define N 100005
using namespace std;
int a[N],b[N],id[N];
bool usd[N];
bool cmp(int a,int b)   {return a>b;}
int main(){
    int n,c=0,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   {
        scanf("%d",a+i);
    }
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++)   {
        if (!usd[a[i]]) {
            b[c++]=a[i];
            id[a[i]]=i;
        }
        usd[a[i]]=1;
    }
    for (int i=0;i<c;i++)
        if (b[i]>=id[b[i]])  ans=max(ans,id[b[i]]);
    cout<<ans<<endl;
    return 0;
}
