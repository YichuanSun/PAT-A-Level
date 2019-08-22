//如果你注定要成为一个很厉害的人
//那么答案就藏在你的血脉中
//一直段错误或者直接错误，不行
#include <bits/stdc++.h>
#define N 10005
#define C 10000
using namespace std;
unordered_map<int,bool> uii;
vector<int> vi[N];  //同性好友加入vi
typedef pair<int,int> pii;
vector<pii> ans;
bool cmp(pii a,pii b)   {
    if (a.first==b.first)   return a.second<b.second;
    return a.first<b.first;
}
int main()  {
    int n,m,k,p,q;
    string a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        if (a.size()==b.size()) {
            vi[abs(stoi(a))].push_back(abs(stoi(b)));
            vi[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        uii[abs(stoi(a))*C+abs(stoi(b))]=uii[abs(stoi(b))*C+abs(stoi(a))]=true;
    }
    cin>>k;
    for (int c=0;c<k;c++)   {
        cin>>p>>q;
        for (int i=0;i<(int)vi[abs(p)].size();i++)  {
            for (int j=0;j<(int)vi[abs(q)].size();j++)  {
                if (vi[abs(p)][i]==abs(q)||vi[abs(q)][j]==abs(p))   continue;
                if (uii[vi[abs(p)][i]*C+vi[abs(q)][j]]==true)   {
                    ans.push_back({vi[abs(p)][i],vi[abs(q)][j]});
                }
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        cout<<ans.size()<<endl;
        for (int x=0;x<(int)ans.size();x++)
            cout<<ans[x].first<<' '<<ans[x].second<<endl;
        ans.clear();
    }
    return 0;
}























////我写的辣鸡，就对了一个样例
//#include <bits/stdc++.h>
//#define N 10005
//using namespace std;
//int g[N][N];
//vector<int> vg[N];  //两个都是，<0为女，>0为男
//typedef pair<int,int> pii;
//vector<pii> vpi;
//void findFriends(int a,int b);
//bool cmp(pii a,pii b)   {
//    if (a.first==b.first)
//        return a.second<b.second;
//    return a.first<b.first;
//}
//int main(){
//    int n,m,k,a,b;
//    cin>>n>>m;
//    for (int i=0;i<m;i++)   {
//        cin>>a>>b;
//        int ta=abs(a),tb=abs(b);
//        g[ta][tb]=a;g[ta][0]=(a>0?1:-1);
//        g[tb][ta]=b;g[tb][0]=(b>0?1:-1);
//        vg[ta].push_back(b);
//        vg[tb].push_back(a);
//    }
//    cin>>k;
//    for (int i=0;i<k;i++)   {
//        cin>>a>>b;
//        findFriends(a,b);
//        vpi.clear();
//
//    }
//    return 0;
//}
//
//void findFriends(int a,int b)    {
//    int ta=abs(a);
//    int jd=(a*b<0?-1:1);   //jd为负则-1，为正则1
//    for (int i=0;i<(int)vg[ta].size();i++)   {
//        int k=abs(vg[ta][i]);
//        if (vg[ta][i]*a<0)  continue;//此后vgtai和a同号
//        for (int j=0;j<(int)vg[k].size();j++)    {
//            int p=abs(vg[k][j]);//如果1，4异号且2,3同号就跳过
//            if (jd==-1&&vg[ta][i]*vg[k][j]>0)    continue;
//            if (jd==1&&vg[ta][i]*vg[k][j]<0)    continue;
//            for (int e=0;e<(int)vg[p].size();e++)   {
//                if (vg[p][e]==b)    {
//                    vpi.push_back({k,p});
//                }
//            }
//        }
//    }
//    sort(vpi.begin(),vpi.end(),cmp);
//    cout<<vpi.size()<<endl;
//    for (int i=0;i<(int)vpi.size();i++)
//        cout<<vpi[i].first<<' '<<vpi[i].second<<endl;
//}
