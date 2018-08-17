#include <bits/stdc++.h>
using namespace std;
long long num[1010];
int main()  {
    int n,b,cnt=0;
    bool flag=true;
    cin>>n>>b;
    while (n)   {
        num[cnt++]=n%b;
        n/=b;
    }
    for (int i=0;i<cnt/2;i++) {
        if (num[i]!=num[cnt-i-1])   flag=false;
    }
    if (flag)   cout<<"Yes\n";
    else    cout<<"No\n";
    cout<<num[cnt-1];
    for (int i=cnt-2;i>=0;i--) cout<<' '<<num[i];
    cout<<'\n';
    return 0;
}
