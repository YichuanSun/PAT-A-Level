#include <bits/stdc++.h>
using namespace std;
struct man{
    string id;
    int sc;
    string sl;
};
struct total{
    string un;
    double score;
    int number;
    total(string ts,double tc,int tn)   {un=ts;score=tc;number=tn;}
};
map<string,pair<int,double> > school;
map<string,vector<man> > msm;
vector<total> vts;
void change(string& ts);
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   {
        man tm;
        cin>>tm.id>>tm.sc>>tm.sl;
        for (int j=0;j<(int)tm.sl.size();j++)   {
            if (tm.sl[j]>='A'&&tm.sl[j]<='Z')
                tm.sl[j]+='a'-'A';
        }
        msm[tm.sl].push_back(tm);
    }
    cout<<msm.size()<<endl;
    map<string,vector<man> >::iterator it=msm.begin(),it1=msm.begin();
    for (;it!=msm.end();it++)   {
        string sch=(*it).first;
        vector<man> tv=(*it).second;
        double td=0;
        for (int j=0;j<(int)tv.size();j++)  {
            school[sch].first++;
            switch((tv[j].id)[0])   {
                case 'T': td=1.5*tv[j].sc;break;
                case 'A': td=tv[j].sc;break;
                case 'B': td=1.0*tv[j].sc/1.5;break;
            }
            school[sch].second+=td;
        }
        school[sch].second=(int)school[sch].second;
    }
    for (;it1!=msm.end();it1++)   {
        string nwschool=(*it1).first;
        vts.push_back(total(nwschool,school[nwschool].second,school[nwschool].first));
    }
    for (int i=0;i<(int)vts.size();i++)
        cout<<vts[i].number<<' '<<vts[i].un<<' '<<vts[i].score<<endl;
    return 0;
}
