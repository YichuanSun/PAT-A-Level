#include <bits/stdc++.h>
using namespace std;
stack<int> s2,s1;
vector<int> v;
bool flag=true;
int main()  {
    int m,n,k,t;
    cin>>m>>n>>k;
    for (int i=n;i>0;i--)   s2.push(i);
    for (int i=0;i<k;i++)   {
        for (int i=0;i<n;i++)   {
            cin>>t;
            v.push_back(t);
        }
        for (unsigned j=0;j<v.size();j++)   {
            while (s1.size()<=m&&(s1.empty()||s1.top()<v[j])) {
                s1.push(s2.top());
                s2.pop();
            }
            if (s1.size()<=m&&!s1.empty()&&s1.top()==v[j])    {
                s1.pop();
            }
            else    {
                flag=false;
                break;
            }
        }
        if (flag)   cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
        flag=true;
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
        for (int i=n;i>0;i--)   s2.push(i);
        v.clear();
    }
    return 0;
}


