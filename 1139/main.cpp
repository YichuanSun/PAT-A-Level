#include <bits/stdc++.h>
#define N 10005
using namespace std;
int g[N][N];
vector<int> vg[N];
int main(){
    int n,m,k,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        int ta=abs(a),tb=abs(b);
        g[ta][tb]=a;g[ta][0]=(a>0?1:-1);
        g[tb][ta]=b;g[tb][0]=(b>0?1:-1);
        vg[ta].push_back(b);
        vg[tb].push_back(a);
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        cin>>a>>b;

    }
    return 0;
}
