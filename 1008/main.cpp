#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()  {
    int n,t,ti=0;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>t;
        v.push_back(t);
    }
    int pre;
    for (int i=0;i<n;i++)   {
        if (i==0)    {
            ti+=v[0]*6+5;
            continue;
        }
        else    pre=v[i-1];
        int now=v[i];
        if (pre<now)    ti+=(now-pre)*6+5;
        else  ti+=(pre-now)*4+5;
    }
    cout<<ti<<endl;
    return 0;
}
