#include <bits/stdc++.h>
using namespace std;
struct time{
    int h,m,s,al;
}time;
struct info{
    time be,en;
    bool vip;
};
vector<info> infos;
int main()  {
    int n,ctn;
    info temp;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   {
        scanf("%d:%d:%d %d %d",&temp.be.h,&temp.be.m,&temp.be.s,&ctn,&temp.vip);
        temp.be.al=temp.be.h*3600+temp.be.m*60+temp.be.s;
        time een;
        een.s=temp.be.s;
        een.m=temp.be.m+ctn;
        een.h=temp.be.h;
        if (een.m>=60)  {
            een.h+=een.m/60;
            een.m%=60;
        }
        een.al=een.h*3600+een.m*60+een.s;
        temp.en=een;
        infos.push_back(temp);
    }
    scanf("%d %d",&k,&m);

    return 0;
}
