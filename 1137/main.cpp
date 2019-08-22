#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> gp,gm,gf,g;
unordered_set<string> ss;
struct stinfo{
    string name;
    int p,m,f,t;
};
vector<stinfo> vs;
bool cmp(stinfo a,stinfo b) {
    if (a.t==b.t)   return a.name<b.name;
    else return a.t>b.t;
}
int main()  {
    string a;
    int p,m,n,sc;
    cin>>p>>m>>n;
    for (int i=0;i<p;i++)   {cin>>a>>sc;gp[a]=(sc<=900)?sc:0;ss.insert(a);}
    for (int i=0;i<m;i++)   {cin>>a>>sc;gm[a]=(sc<=100)?sc:0;ss.insert(a);}
    for (int i=0;i<n;i++)   {cin>>a>>sc;gf[a]=(sc<=100)?sc:0;ss.insert(a);}
    unordered_set<string>::iterator it=ss.begin();
    for (;it!=ss.end();it++)    {
        stinfo ns;
        ns.name=*it;
        ns.p=(gp[*it]==0?-1:gp[*it]);
        ns.m=(gm[*it]==0?-1:gm[*it]);
        ns.f=(gf[*it]==0?-1:gf[*it]);
        if (ns.p<200)   ns.t=0;
        else    {
            if (ns.m>ns.f)  ns.t=round(0.4*gm[*it]+0.6*gf[*it]);
            else    ns.t=ns.f;
        }
        vs.push_back(ns);
    }
    sort(vs.begin(),vs.end(),cmp);
    //cout<<vs.size()<<endl;
    for (int i=0;i<(int)vs.size();i++)
        if (vs[i].t>=60&&vs[i].t<=100)
        cout<<vs[i].name<<' '<<vs[i].p<<' '<<vs[i].m<<' '<<vs[i].f<<' '<<vs[i].t<<endl;
    return 0;
}
