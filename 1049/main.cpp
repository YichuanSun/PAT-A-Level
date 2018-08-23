#include <bits/stdc++.h>
using namespace std;

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,cnt=0;
    cin>>n;
    for (int i=1;i<=n;i++)  {
        t=i;
        if (t%10!=1)
        while (t!=0)    {
            if (t%10==1)    cnt++;
            t/=10;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
