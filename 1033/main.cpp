#include <bits/stdc++.h>
#define INF 0x7fffffff;
using namespace std;
struct ps{
    double p,d;
    void read() {cin>>p>>d;}
    bool operator < (const ps &a)const{
        return (a.p==p)?(d<a.d):(p<a.p);
    }
};
ps road[505];
int n;
double C,D,d,maxdis=0,mincost=INF;
void dfs(int now,double cost,double fuel) {
    maxdis=max(maxdis,road[now].d+C*d);
    int minx=now;
    for (int i=now+1;i<n;i++)   {
        if (C*d+road[now].d>=road[i].d) {
            if (road[i].p<road[now].p)  {
                double g=(road[i].d-road[now].d)/d;
                double r=(g-fuel)*road[now].p;
                if (g>fuel) dfs(i,cost+r,0);
                else    dfs(i,cost,fuel-g);
                return;
            }
            if (minx==now||road[minx].p>road[i].p) minx=i;
        }
    }
    if (road[now].d+C*d>=D) {
        double ff=(D-road[now].d)/d;
        if (ff>fuel)    mincost=min(mincost,cost+(ff-fuel)*road[now].p);
        else    mincost=min(mincost,cost);
    }
    if (minx>now)  {
        double v=(C-fuel)*road[now].p;
        dfs(minx,cost+v,C-(road[minx].d-road[now].d)/d);
    }
}
int main()  {
    cin>>C>>D>>d>>n;
    for (int i=0;i<n;i++)   road[i].read();
    sort(road,road+n);
    dfs(0,0,0);
    cout.setf(ios::fixed);
    if (road[0].d>0)    cout<<"The maximum travel distance = 0.00"<<endl;
    if (maxdis<1.0*D)   cout<<"The maximum travel distance = "<<setprecision(2)<<maxdis<<endl;
    else    cout<<mincost<<endl;
    return 0;
}
