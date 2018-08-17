#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef struct record{
    int h,m,s,ti,cost;
}record;
vector<record> rs;
bool cmp(record a,record b) {
    return a.ti<b.ti;
}
int main()  {
    int n,k,waittime=0;
    record r;
    int wi[N];
    fill(wi,wi+N,28800);
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++)   {
        scanf("%d:%d:%d %d",&r.h,&r.m,&r.s,&r.cost);
        if (r.cost>60)  r.cost=60;
        if (r.h>=17&&(r.m>0||r.s>0))    continue;
        r.ti=r.h*3600+r.m*60+r.s;
        r.cost*=60;
        rs.push_back(r);
    }
    sort(rs.begin(),rs.end(),cmp);
    for (int i=0;i<rs.size();i++)   {
        int earlist=wi[0],winum=0;
        for (int j=0;j<k;j++)   {
            if (wi[j]<earlist)  {
                winum=j;
                earlist=wi[j];
            }
        }
        if (rs[i].ti<earlist)   {
            waittime+=earlist-rs[i].ti;
            wi[winum]=earlist+rs[i].cost;
        }
        else    wi[winum]=rs[i].ti+rs[i].cost;
    }
    if (rs.size()!=0)   printf("%.1f\n",1.0*waittime/60/rs.size());
    else    printf("0.0\n");
    return 0;
}





