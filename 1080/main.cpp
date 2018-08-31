#include <bits/stdc++.h>
using namespace std;
struct sud{
    int num,ge,rk;
    double avg;
}ss[40005];
int n,m,k;
vector<int> school[105];
int line[105];
bool isadmit[40005];
bool cmp(int a,int b)   {
    if (ss[a].avg==ss[b].avg)
        return ss[a].ge>ss[b].ge;
    return ss[a].avg>ss[b].avg;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ge,gi,ts;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++)   cin>>line[i];
    for (int i=0;i<n;i++)   {
        cin>>ge>>gi;
        ss[i].num=i;
        ss[i].avg=1.0*(ge+gi)/2;
        ss[i].ge=ge;
        for (int j=0;j<k;j++)   {
            cin>>ts;
            school[ts].push_back(i);
        }
    }
    for (int i=0;i<m;i++)   {
        sort(school[i].begin(),school[i].end(),cmp);
        ss[school[i][0]].rk=1;
        int sz=school[i].size();
        for (int j=1;j<sz;j++)   {
            if (ss[school[i][j]].avg==ss[school[i][j-1]].avg) {
                if (ss[school[i][j]].ge==ss[school[i][j-1]].ge)
                    ss[school[i][j]].rk=ss[school[i][j-1]].rk;
                else
                    ss[school[i][j]].rk=j+1;
            }
            else
                ss[school[i][j]].rk=j+1;
        }
        int fate=1;
        for (int j=0;j<sz;j++)   {
            if (isadmit[school[i][j]]) continue;
            if (line[i]>0) {
                fate=ss[school[i][j]].rk;
                isadmit[school[i][j]]=true;
                line[i]--;
                cout<<school[i][j]<<' ';
            }
            else    {
                if (line[i]<=0&&j==0)    break;
                else    {
                    while (j<sz&&fate==ss[school[i][j]].rk){
                        if (isadmit[school[i][j]]) continue;
                        isadmit[school[i][j]]=true;
                        line[i]--;
                        cout<<school[i][j]<<' ';
                        j++;
                    }
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
