#include <bits/stdc++.h>
#define N 1005
using namespace std;
vector<int> v;
int staticTree[N],cnt=0;
void buildTree(int a);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,tmp;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    buildTree(1);
    cout<<staticTree[1];
    for (int i=2;i<=n;i++)   cout<<' '<<staticTree[i];
    cout<<endl;
    return 0;
}

void buildTree(int a)   {
    if (a>(int)v.size()) return;
    buildTree(2*a);
    staticTree[a]=v[cnt++];
    buildTree(2*a+1);
}


