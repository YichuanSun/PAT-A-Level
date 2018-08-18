#include <bits/stdc++.h>
using namespace std;
struct stu{
    string name,su;
    char sex;
    int score;
};
bool cmpHtoL(stu a,stu b)  {
    return a.score>b.score;
}
bool cmpLtoH(stu a,stu b)   {
    return a.score<b.score;
}
vector<stu> m,f;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    stu ts;
    int n,cnt=0;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>ts.name>>ts.sex>>ts.su>>ts.score;
        if (ts.sex=='M')    m.push_back(ts);
        else if (ts.sex=='F')   f.push_back(ts);
    }
    sort(m.begin(),m.end(),cmpLtoH);
    sort(f.begin(),f.end(),cmpHtoL);
    if (f.size()==0)   {
        cout<<"Absent"<<endl;
        cnt++;
    }
    else cout<<f[0].name<<' '<<f[0].su<<endl;
    if (m.size()==0)   {
        cout<<"Absent"<<endl;
        cnt++;
    }
    else cout<<m[0].name<<' '<<m[0].su<<endl;
    if (cnt==0) cout<<f[0].score-m[0].score<<endl;
    else cout<<"NA"<<endl;
    return 0;
}


