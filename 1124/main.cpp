#include <bits/stdc++.h>
using namespace std;
vector<string> v;
set<string> si;
int main(){
    v.push_back("");
    int m,n,s,sp=0,cor=0;
    string c;
    cin>>m>>n>>s;
    for (int i=0;i<m;i++)   {
        cin>>c;
        v.push_back(c);
    }
    for (int i=s;i<=m;i++)  {
        if ((i-cor-s)%n==0) {
            if (si.count(v[i])==0)  {
                si.insert(v[i]);
                cout<<v[i]<<endl;
                sp=1;
            }
            else cor++; //说明该获奖者已经存在
        }
    }
    if (sp==0)  cout<<"Keep going..."<<endl;
    return 0;
}
