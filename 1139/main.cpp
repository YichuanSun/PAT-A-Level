#include <bits.stdc++.h>
using namespace std;

int main()  {
    int n,m,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;

    }
    return 0;
}























//我写的辣鸡，就对了一个样例
#include <bits/stdc++.h>
#define N 10005
using namespace std;
int g[N][N];
vector<int> vg[N];  //两个都是，<0为女，>0为男
typedef pair<int,int> pii;
vector<pii> vpi;
void findFriends(int a,int b);
bool cmp(pii a,pii b)   {
    if (a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
int main(){
    int n,m,k,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        int ta=abs(a),tb=abs(b);
        g[ta][tb]=a;g[ta][0]=(a>0?1:-1);
        g[tb][ta]=b;g[tb][0]=(b>0?1:-1);
        vg[ta].push_back(b);
        vg[tb].push_back(a);
    }
    cin>>k;
    for (int i=0;i<k;i++)   {
        cin>>a>>b;
        findFriends(a,b);
        vpi.clear();

    }
    return 0;
}

void findFriends(int a,int b)    {
    int ta=abs(a);
    int jd=(a*b<0?-1:1);   //jd为负则-1，为正则1
    for (int i=0;i<(int)vg[ta].size();i++)   {
        int k=abs(vg[ta][i]);
        if (vg[ta][i]*a<0)  continue;//此后vgtai和a同号
        for (int j=0;j<(int)vg[k].size();j++)    {
            int p=abs(vg[k][j]);//如果1，4异号且2,3同号就跳过
            if (jd==-1&&vg[ta][i]*vg[k][j]>0)    continue;
            if (jd==1&&vg[ta][i]*vg[k][j]<0)    continue;
            for (int e=0;e<(int)vg[p].size();e++)   {
                if (vg[p][e]==b)    {
                    vpi.push_back({k,p});
                }
            }
        }
    }
    sort(vpi.begin(),vpi.end(),cmp);
    cout<<vpi.size()<<endl;
    for (int i=0;i<(int)vpi.size();i++)
        cout<<vpi[i].first<<' '<<vpi[i].second<<endl;
}
