#include <bits/stdc++.h>
using namespace std;
int a[100005];
map<int,bool> cnt;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>a[i];
        cnt[a[i]]=true;
    }
    for (int i=1;i<100005;i++)  {
        if (!cnt[i]) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
