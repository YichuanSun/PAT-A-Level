#include <bits/stdc++.h>
#define N 30
using namespace std;
class node{
public:
    string d;
    int lc,rc;
}ns[N];
bool fd[N];
string inOT(int root);
int main()  {
    int n,root=1;
    cin>>n;
    for (int i=1;i<=n;i++)   {
        cin>>ns[i].d>>ns[i].lc>>ns[i].rc;
        fd[ns[i].lc]=fd[ns[i].rc]=true;
    }
    while (fd[root])    root++;
    string ans=inOT(root);
    if (ans[0]=='(')    ans=ans.substr(1,ans.size()-2);
    cout<<ans<<endl;
    return 0;
}
string inOT(int root) {
    if (ns[root].lc==-1&&ns[root].rc!=-1) return "(" + ns[root].d + inOT(ns[root].rc) + ")";
    if (ns[root].lc==-1&&ns[root].rc==-1)    return ns[root].d;
    if (ns[root].lc!=-1&&ns[root].rc!=-1)    return "(" + inOT(ns[root].lc) + ns[root].d + inOT(ns[root].rc) + ")";
    return "";
}
