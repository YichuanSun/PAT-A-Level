#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int s[N];
set<int> si;
vector<int> vi,ans;
int main()  {
    fill(s,s+N,-1);
    int n,k,a,b;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>a>>b;
        s[a]=b;
        s[b]=a;
    }
    cin>>k;
    for (int i=0;i<k;i++)   {cin>>a;vi.push_back(a);si.insert(a);}
    for (int i=0;i<k;i++)
        if (s[vi[i]]==-1||si.count(s[vi[i]])==0)  ans.push_back(vi[i]);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i=0;i<(int)ans.size();i++)
        printf("%05d%c",ans[i],(i==(int)ans.size()-1)?'\n':' ');
    return 0;
}
