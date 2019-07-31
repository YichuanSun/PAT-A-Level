#include <bits/stdc++.h>
#define N 10005
using namespace std;
set<int> si;
int a[N];
int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        si.insert(a[i]);
    }
    for (int i=0;i<m;i++)   {
        int j=0,u,v;
        scanf("%d%d",&u,&v);
        if (!si.count(u)&&!si.count(v)) {printf("ERROR: %d and %d are not found.\n",u,v);continue;}
        else if (!si.count(u)||!si.count(v))    {printf("ERROR: %d is not found.\n",(!si.count(u))?u:v);continue;}
        for (;j<n;j++)
            if ((a[j]>u&&a[j]<=v)||(a[j]<=u&&a[j]>v)||(a[j]==u)||(a[j]==v))   break;
        if ((a[j]>u&&a[j]<v)||(a[j]<u&&a[j]>v)) printf("LCA of %d and %d is %d.\n",u,v,a[j]);
        else if ((a[j]==u)||(a[j]==v))  printf("%d is an ancestor of %d.\n",a[j],(a[j]==u)?v:u);
    }
    return 0;
}
