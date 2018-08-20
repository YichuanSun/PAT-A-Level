#include <bits/stdc++.h>
using namespace std;
map<string,vector<int> > sts;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,sub,num;
    cin>>n>>k;
    string tst;
    for (int i=0;i<k;i++)   {
        cin>>sub>>num;
        for (int i=0;i<num;i++) {
            cin>>tst;
            sts[tst].push_back(sub);
        }
    }
    for (int i=0;i<n;i++)   {
        cin>>tst;
        cout<<tst<<' '<<sts[tst].size();
        sort(sts[tst].begin(),sts[tst].end());
        for (int i=0;i<sts[tst].size();i++) cout<<' '<<sts[tst][i];
        cout<<endl;
    }
    return 0;
}

