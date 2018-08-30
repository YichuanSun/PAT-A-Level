/*
蠢到家的算法，直接map+vector排序，没超时真是幸运
*/
#include <bits/stdc++.h>
using namespace std;
int ms[7];
struct info{
    int id,tot,rk,sov;
    int sc[7]={-5,-5,-5,-5,-5,-5,-5};
};
map<int,info> pp;
vector<info> v;
bool cmp(info a,info b) {
    if (a.tot==b.tot)   {
        if (a.sov==b.sov)   {
            return a.id<b.id;
        }
        return a.sov>b.sov;
    }
    return a.tot>b.tot;
}
int main()  {
    int n,m,k;
    int id,pn,score;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++)  scanf("%d",&ms[i]);
    for (int i=0;i<k;i++)   {
        scanf("%d%d%d",&id,&pn,&score);
        pp[id].id=id;
        pp[id].sc[pn]=max(score,pp[id].sc[pn]);
    }
    map<int,info>::iterator it1=pp.begin();
    for (;it1!=pp.end();it1++){
        bool flag=false;
        for (int j=1;j<=m;j++)  {
            if ((*it1).second.sc[j]==ms[j]) (*it1).second.sov++;
            if ((*it1).second.sc[j]>=0)    {
                flag=true;
                (*it1).second.tot+=(*it1).second.sc[j];
            }
        }
        if (flag)   v.push_back((*it1).second);
    }
    sort(v.begin(),v.end(),cmp);
    if (!v.empty()) {
        v[0].rk=1;
        printf("%d %05d %d",v[0].rk,v[0].id,v[0].tot);
        for (int j=1;j<=m;j++){
            if (v[0].sc[j]==-1) printf(" 0");
            else if (v[0].sc[j]!=-5) printf(" %d",v[0].sc[j]);
            else    printf(" -");
        }
        printf("\n");
    }
    for (unsigned i=1;i<v.size();i++)   {
        if (v[i].tot==v[i-1].tot) v[i].rk=v[i-1].rk;
        else    v[i].rk=i+1;
        printf("%d %05d %d",v[i].rk,v[i].id,v[i].tot);
        for (int j=1;j<=m;j++){
            if (v[i].sc[j]==-1) printf(" 0");
            else if (v[i].sc[j]!=-5) printf(" %d",v[i].sc[j]);
            else    printf(" -");
        }
        printf("\n");
    }
    return 0;
}


