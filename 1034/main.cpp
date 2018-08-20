#include <bits/stdc++.h>
using namespace std;

typedef std::set<string>::iterator si;
typedef pair<string,int> ppx;

map<string,map<string,int> > graph;
map<string,int> ms;
map<string,bool> used;
set<string> ss;
vector<ppx>   tv,ans;
int num,all;

void dfs(string x);
bool cmp(ppx a,ppx b)   {
    return a.second>b.second;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,temp;
    cin>>n>>k;
    string s1,s2;
    for (int i=0;i<n;i++)   {
        cin>>s1>>s2>>temp;
        graph[s1][s2]+=temp;
        graph[s2][s1]+=temp;
        ss.insert(s1);
        ss.insert(s2);
    }
    si i1=ss.begin();
    for (;i1!=ss.end();i1++)  {
        if (!used[*i1])    {
            //cout<<*i1<<endl;
            num=1;
            dfs(*i1);
            all/=2;
            //cout<<all<<' '<<num<<endl;
            if (!tv.empty())    {
                ppx nppx=ppx("",0);
                for (unsigned j=0;j<tv.size();j++)
                    if (tv[j].second>nppx.second)  nppx=tv[j];
                if (num>2&&all>k)   ans.push_back(ppx(nppx.first,num));
                all=num=0;
                tv.clear();
            }
        }
    }
    cout<<ans.size()<<endl;
    for (unsigned i=0;i<ans.size();i++) {
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
    return 0;
}

void dfs(string x) {
    si tsi;
    used[x]=true;
    for (tsi=ss.begin();tsi!=ss.end();tsi++)    {
        if (graph[x][*tsi]!=0)  {
            ms[x]+=graph[x][*tsi];
            all+=graph[x][*tsi];
            if (!used[*tsi])  {
                num++;
                dfs(*tsi);
            }
        }
    }
    tv.push_back(make_pair(x,ms[x]));
}
