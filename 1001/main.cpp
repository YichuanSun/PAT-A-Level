#include <bits/stdc++.h>
using namespace std;

int main()  {
    string str;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int a,b,cnt=0,sum;
    cin>>a>>b;
    if (a+b<0)  cout<<'-';
    sum=abs(a+b);
    if (sum==0) {
        cout<<0<<endl;
        return 0;
    }
    for (int i=1;sum!=0;i++)   {
        str=sum%10+'0';
        sum/=10;
        if (i%3==0&&sum!=0) str+=',';
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}
