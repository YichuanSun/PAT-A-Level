#include <bits/stdc++.h>
using namespace std;
struct stu{
    string name;
    string id;
    int grade;
};
vector<stu> tv;
vector<stu> ans;
bool cmp(stu a,stu b)   {
    return a.grade>b.grade;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,small,big;
    stu ts;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>ts.name>>ts.id>>ts.grade;
        tv.push_back(ts);
    }
    cin>>small>>big;
    for (vector<stu>::iterator it1=tv.begin();it1<=tv.end();it1++)
        if ((*it1).grade>=small&&(*it1).grade<=big)
            ans.push_back(*it1);
    sort(ans.begin(),ans.end(),cmp);
    if (ans.empty()) {
        cout<<"NONE"<<endl;
        return 0;
    }
    for (unsigned i=0;i<ans.size();i++)  {
        cout<<ans[i].name<<' '<<ans[i].id<<endl;
    }
    return 0;
}
