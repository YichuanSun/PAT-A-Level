#include <bits/stdc++.h>
#define N 100005
using namespace std;
int a[N],b[N],id[N];
bool usd[N];
bool cmp(int a,int b)   {return a>b;}
int main(){
    int i=0,n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   {
        scanf("%d",a+i);
    }
    sort(a,a+n,cmp);
    while (i<n&&a[i]>i+1)   i++;
    cout<<i<<endl;
    return 0;
}
