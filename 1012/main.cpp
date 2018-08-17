#include <bits/stdc++.h>
using namespace std;
const int INF=99999;
typedef struct st{
    int num,c,m,e,a,Rank,tmprank;
    char sub;
}st;
vector<st> students,sc,sm,se,sa;
map<int,st> info;
bool cmpc(st aa,st bb) {
    return aa.c>bb.c;
}
bool cmpm(st aa,st bb)  {
    return aa.m>bb.m;
}
bool cmpe(st aa,st bb)  {
    return aa.e>bb.e;
}
bool cmpa(st aa,st bb)  {
    return aa.a>bb.a;
}
int main()  {
    int n,m,se;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)   {
        st s1;
        scanf("%d %d %d %d",&s1.num,&s1.c,&s1.m,&s1.e);
        s1.a=1.0*(s1.c+s1.m+s1.e)/3;
        s1.Rank=-1;
        s1.tmprank=INF;
        students.push_back(s1);
    }
    sort(students.begin(),students.end(),cmpa);
    for (int i=0;i<students.size();i++) {
        if (i==0)   students[i].tmprank=0;
        else if (students[i].tmprank>=students[i-1].tmprank)     students[i].tmprank=students[i-1].tmprank;
        else    students[i].tmprank=i;
        if (students[i].Rank>students[i].tmprank+1) {
            students[i].Rank=students[i].tmprank+1;
            students[i].sub='A';
        }
    }
    sort(students.begin(),students.end(),cmpc);
    for (int i=0;i<students.size();i++) {
        if (i==0)   students[i].tmprank=0;
        else if (students[i].tmprank>=students[i-1].tmprank)     students[i].tmprank=students[i-1].tmprank;
        else    students[i].tmprank=i;
        if (students[i].Rank>students[i].tmprank+1) {
            students[i].Rank=students[i].tmprank+1;
            students[i].sub='C';
        }
    }
    sort(students.begin(),students.end(),cmpm);
    for (int i=0;i<students.size();i++) {
        if (i==0)   students[i].tmprank=0;
        else if (students[i].tmprank>=students[i-1].tmprank)     students[i].tmprank=students[i-1].tmprank;
        else    students[i].tmprank=i;
        if (students[i].Rank>students[i].tmprank+1) {
            students[i].Rank=students[i].tmprank+1;
            students[i].sub='M';
        }
    }
    sort(students.begin(),students.end(),cmpe);
    for (int i=0;i<students.size();i++) {
        if (i==0)   students[i].tmprank=0;
        else if (students[i].tmprank>=students[i-1].tmprank)     students[i].tmprank=students[i-1].tmprank;
        else    students[i].tmprank=i;
        if (students[i].Rank>students[i].tmprank+1) {
            students[i].Rank=students[i].tmprank+1;
            students[i].sub='E';
        }
    }
    for (int i=0;i<students.size();i++) info[students[i].num]=students;
    for (int i=0;i<m;i++)   {
        scanf("%d",&se);
        if (info.find(se)==info.end())  cout<<"N/A"<<endl;
        else    cout<<info[se].Rank<<' '<<info[se].sub<<endl;
    }
    return 0;
}
