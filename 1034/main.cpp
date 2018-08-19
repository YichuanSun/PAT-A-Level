#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string> suf;
map<suf,int> graph;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    suf tsuf;
    int n,k,va;
    string tes;
    cin>>n>>k;
    for (int i=0;i<n;i++)   {
        cin>>tsuf.first>>tsuf.second>>va;
        graph[suf]=va;
        swap(tsuf.first,tsuf.second);
        graph[suf]=va;
    }

    return 0;
}
