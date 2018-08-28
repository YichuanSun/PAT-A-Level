#include <bits/stdc++.h>
using namespace std;
struct cake{
    double save,pr,avg;
}cakes[1005];
bool cmp(cake a,cake b) {
    return a.avg>b.avg;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>cakes[i].save;
    for (int i=0;i<n;i++)   {
        cin>>cakes[i].pr;
        cakes[i].avg=cakes[i].pr/cakes[i].save;
    }
    sort(cakes,cakes+n,cmp);
    int i=0;
    double ins=0;
    while (m>0&&n!=0&&i<n)   {
        if (cakes[i].save<m){
            m-=cakes[i].save;
            ins+=cakes[i].pr;
        }
        else    {
            ins+=m/cakes[i].save*cakes[i].pr;
            m=0;
        }
        i++;
    }
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<ins<<endl;
    return 0;
}


