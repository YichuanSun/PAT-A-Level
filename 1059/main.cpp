#include <bits/stdc++.h>
using namespace std;

int main()  {
    long long int n;
    int flag=0;
    cin>>n;
    if (n==1)   {
        cout<<"1=1"<<endl;
        return 0;
    }
    cout<<n<<'=';
    for (int i=2;i<=n;i++)  {
        //if (i*i>n)  break;
        if (n%i!=0) continue;
        int cnt=0;
        while (n%i==0)    {
            n/=i;
            cnt++;
        }
        if (flag)    cout<<'*';
        if (cnt==1) cout<<i;
        else cout<<i<<'^'<<cnt;
        flag=1;
    }
    cout<<endl;
    return 0;
}
