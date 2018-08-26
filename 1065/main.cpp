#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d;
bool flag;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)   {
        cin>>a>>b>>c;
        cout<<"Case #"<<i<<": ";
        d=a+b;
        //cout<<"d=\t"<<d<<endl;
        if (a<0&&b<0&&d>=0) flag=false;
        else if (a>0&&b>0&&d<=0)    flag=true;
        else    flag=d>c;
        if (flag)   cout<<"true"<<endl;
        else    cout<<"false"<<endl;
    }
    return 0;
}
