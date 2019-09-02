#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()  {
    ll n;
    cin>>n;
    string a;
    for (int i=0;i<n;i++)   {
        cin>>a;
        int sz=(int)a.size();
        string b=a.substr(0,sz/2);
        string c=a.substr(sz/2);
        ll aa=stoll(a,nullptr,10);
        ll bb=stoll(b,nullptr,10);
        ll cc=stoll(c,nullptr,10);
        ll dd=bb*cc;
        if (dd==0)  cout<<"No"<<endl;
        else if (aa%dd==0)   cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
