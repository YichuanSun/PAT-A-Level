#include <bits/stdc++.h>
using namespace std;
int a[10005],n,m,cnt,sum;
bool ok;
vector<int> ans;
void dfs(int p,int m);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)   {
        cin>>a[i];
        sum+=a[i];
    }
    if (sum<m)  {
        cout<<"No Solution"<<endl;
        return 0;
    }
    sort(a,a+n);
    dfs(0,m);
    if (!ok)    cout<<"No Solution"<<endl;
    return 0;
}

void dfs(int p,int m) {
    //cout<<"Case:"<<cnt++<<endl;
    //if (!ans.empty()&&ans[1]==3)    system("pause");
    if (ok) return;
    if (m<0)    return;
    else if (m==0)   {
        ok=true;
        cout<<ans[0];
        for (unsigned i=1;i<ans.size();i++)
            cout<<' '<<ans[i];
        cout<<endl;
        return;
    }
//    if (!ans.empty())   cout<<ans[0];
//    for (unsigned i=1;i<ans.size();i++)
//        cout<<' '<<ans[i];
//    cout<<endl;
    for (int i=p;i<n;i++)   {
        ans.push_back(a[i]);
        dfs(i+1,m-a[i]);
        ans.erase(ans.end()-1);
    }
}
