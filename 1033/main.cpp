#include <bits/stdc++.h>
using namespace std;
struct ps{
    double p;
    int d;
    void read() {cin>>p>>d;}
    bool operator < (const ps &a)const{
        return (a.p==p)?(d<a.d):(p<a.p);
    }
};
ps road[505];
int main()  {
    int c,D,d,n;
    cin>>c>>D>>d>>n;
    for (int i=0;i<n;i++)   road[i].read();
    cout<<road[2].p<<' '<<road[2].d<<endl;
    return 0;
}
