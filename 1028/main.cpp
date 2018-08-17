#include <bits/stdc++.h>
using namespace std;
struct student  {
    string num;
    string name;
    int score;
};
vector<student> sts;
bool cmp1(student a,student b)  {
    return a.num<b.num;
}
bool cmp2(student a,student b)  {
    if (a.name==b.name)
        return a.num<b.num;
    return a.name<b.name;
}
bool cmp3(student a,student b)  {
    if (a.score==b.score)
        return a.num<b.num;
    return a.score<b.score;
}
void sot1();
void sot2();
void sot3();
int main()  {
    int n,k;
    student stemp;
    cin>>n>>k;
    for (int i=0;i<n;i++)   {
        cin>>stemp.num>>stemp.name>>stemp.score;
        sts.push_back(stemp);
    }
    switch(k)   {
        case 1: sot1();break;
        case 2: sot2();break;
        case 3: sot3();break;
    }
    return 0;
}

void sot1() {
    sort(sts.begin(),sts.end(),cmp1);
    for (unsigned i=0;i<sts.size();i++)
        cout<<sts[i].num<<' '<<sts[i].name<<' '<<sts[i].score<<endl;
}

void sot2() {
    sort(sts.begin(),sts.end(),cmp2);
    for (unsigned i=0;i<sts.size();i++)
        cout<<sts[i].num<<' '<<sts[i].name<<' '<<sts[i].score<<endl;
}

void sot3() {
    sort(sts.begin(),sts.end(),cmp3);
    for (unsigned i=0;i<sts.size();i++)
        cout<<sts[i].num<<' '<<sts[i].name<<' '<<sts[i].score<<endl;
}
