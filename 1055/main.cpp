#include <bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int worth,age;
};
vector<person> ps;
bool cmp(person a,person b)  {
    if (a.worth==b.worth)   {
        if (a.age==b.age)   {
            return a.name<b.name;
        }
        return a.age<b.age;
    }
    return a.worth>b.worth;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,num,la,ha;
    person tp;
    cin>>n>>k;
    for (int i=0;i<n;i++)   {
        cin>>tp.name>>tp.age>>tp.worth;
        ps.push_back(tp);
    }
    sort(ps.begin(),ps.end(),cmp);
    for (int i=1;i<=k;i++)  {
        cin>>num>>la>>ha;
        cout<<"Case #"<<i<<':'<<endl;
        int spot=0;
        for (unsigned q=0;q<ps.size();q++)  {
            if (ps[q].age>=la&&ps[q].age<=ha)   {
                cout<<ps[q].name<<' '<<ps[q].age<<' '<<ps[q].worth<<endl;
                spot++;
            }
            if (spot==num)  break;
        }
        if (spot==0)    cout<<"None"<<endl;
    }
    return 0;
}
