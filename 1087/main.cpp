#include <bits/stdc++.h>
using namespace std;
map<string,int> happy;
map<string,map<string,double> > g;
map<string,string> path;
int main()  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,th;
    double t;
    string st1,st2,be,tt;
    cin>>n>>k>>be;
    for (int i=0;i<n-1;i++)   {
        cin>>tt>>th;
        happy[tt]=th;
    }
    for (int i=0;i<k;i++)   {
        cin>>st1>>st2>>t;
        g[st1][st2]=t;
    }

    return 0;
}



