#include <bits/stdc++.h>
using namespace std;
vector<int> a,b,c;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n1,n2,te;
    cin>>n1;
    for (int i=0;i<n1;i++)  {
        cin>>te;
        a.push_back(te);
    }
    cin>>n2;
    for (int i=0;i<n2;i++)  {
        cin>>te;
        b.push_back(te);
    }
    for (signed i=0;i<n1;i++) c.push_back(a[i]);
    for (signed i=0;i<n2;i++) c.push_back(b[i]);
    sort(c.begin(),c.end());
    int spot=0;
    if (c.size()&1) spot=c.size()/2;
    else    spot=c.size()/2-1;
    cout<<c[spot]<<endl;
    return 0;
}
