#include <bits/stdc++.h>
using namespace std;
bool used[10005];
bool isPrime(int m);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n,tmp;
    cin>>m>>n;
    while (!isPrime(m)) m++;
    for (int i=0;i<n;i++)   {
        cin>>tmp;
        int j;
        for (j=0;j<m;j++) {
            if (used[(tmp+j*j)%m]==false)   {
                used[(tmp+j*j)%m]=true;
                cout<<(tmp+j*j)%m<<(i==n-1?'\n':' ');
                break;
            }
        }
        if (j==m)
            cout<<'-'<<((i==n-1)?'\n':' ');
    }
    return 0;
}

bool isPrime(int m) {
    if (m<=1)   return false;
    if (m==2)   return true;
    for (int i=2;i*i<=m;i++)
        if (m%i==0)
            return false;
    return true;
}
