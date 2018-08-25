#include <bits/stdc++.h>
using namespace std;
typedef set<int>::iterator si;
set<int> ss[55];
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    int n,nn,t,e1,e2;
    cin>>n;
    for (int i=1;i<=n;i++)   {
        cin>>nn;
        for (int j=0;j<nn;j++)  {
            cin>>t;
            ss[i].insert(t);
        }
    }
    cin>>nn;
    for (int i=0;i<nn;i++)  {
        cin>>e1>>e2;
        int cnt=0;
        for (si j=ss[e1].begin();j!=ss[e1].end();j++)  {
            si it1=ss[e2].find(*j);
            if (it1!=ss[e2].end())  cnt++;
        }
        int tmp=ss[e1].size()+ss[e2].size()-cnt;
        double ans=1.0*cnt/tmp*100;
        cout<<setprecision(1)<<ans<<'%'<<endl;
    }
    return 0;
}
