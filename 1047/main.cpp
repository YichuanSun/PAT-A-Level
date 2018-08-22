#include <bits/stdc++.h>
using namespace std;
map<int,vector<string> > lis;
int main()  {
    int n,k,tn,t;
    string name;
    cin>>n>>k;
    for (int i=0;i<n;i++)   {
        cin>>name;
        cin>>tn;
        for (int i=0;i<tn;i++)  {
            cin>>t;
            lis[t].push_back(name);
        }
    }
    for (int i=1;i<=k;i++)  {
        sort(lis[i].begin(),lis[i].end());
        cout<<i<<' '<<lis[i].size()<<endl;
        for (unsigned j=0;j<lis[i].size();j++)
            cout<<lis[i][j]<<endl;
    }
    return 0;
}
