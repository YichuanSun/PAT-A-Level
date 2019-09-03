#include <bits/stdc++.h>
#define N 10005
using namespace std;
int a[N];
int main()  {
    int n,sm=0;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++)
        if (i!=0)  sm=(sm+a[i])/2;
        else sm=a[i];
    cout<<sm<<endl;
    return 0;
}
