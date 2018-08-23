#include <bits/stdc++.h>
using namespace std;
map<int,int> pix;
int main()  {
    int m,n,t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for (int i=0;i<n;i++)   {
        for (int i=0;i<m;i++)   {
            cin>>t;
            pix[t]++;
        }
    }
    std::map<int,int>::iterator i=pix.begin();
    int mx=0,ans=0;
    for (;i!=pix.end();i++) {
        if ((*i).second>mx) {
            mx=(*i).second;
            ans=(*i).first;
        }
    }
    cout<<ans<<endl;
    return 0;
}
