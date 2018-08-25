#include <bits/stdc++.h>
using namespace std;
struct pep{
    int num,t,v,tot;
};
vector<pep> sg,nb,fm,sm;
bool cmp(pep a,pep b)   {
    if (a.tot==b.tot)   {
        if (a.v==b.v)   {
            return a.num<b.num;
        }
        return a.v>b.v;
    }
    return a.tot>b.tot;
}
void prf(vector<pep> tt)    {
    for (unsigned i=0;i<tt.size();i++)
        cout<<tt[i].num<<' '<<tt[i].v<<' '<<tt[i].t<<endl;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,l,h;
    pep tp;
    cin>>n>>l>>h;
    for (int i=0;i<n;i++)   {
        cin>>tp.num>>tp.v>>tp.t;
        if (tp.v<l||tp.t<l) continue;
        tp.tot=tp.v+tp.t;
        if (tp.v>=h&&tp.t>=h)   sg.push_back(tp);
        else if (tp.v>=h&&tp.t<h)   nb.push_back(tp);
        else if (tp.v>=tp.t&&tp.v<h&&tp.t<h)    fm.push_back(tp);
        else    sm.push_back(tp);
    }
    cout<<sg.size()+nb.size()+fm.size()+sm.size()<<endl;
    sort(sg.begin(),sg.end(),cmp);
    sort(nb.begin(),nb.end(),cmp);
    sort(fm.begin(),fm.end(),cmp);
    sort(sm.begin(),sm.end(),cmp);
    prf(sg),prf(nb),prf(fm),prf(sm);
    return 0;
}
