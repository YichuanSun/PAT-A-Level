#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
map<string,int> happy,d;
map<string,map<string,int> > g;
map<string,string> path;
map<string,bool> used;
set<string> ss;
stack<string> ans;
string be;
void dijkstra(string be);
int maxhappy=-1,shts=INF,rnum;
double avghappy=-1;
int main()  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,th;
    int t;
    string st1,st2,tt;
    cin>>n>>k>>be;
    ss.insert(be);
    for (int i=0;i<n-1;i++)   {
        cin>>tt>>th;
        happy[tt]=th;
        ss.insert(tt);
    }
    for (int i=0;i<k;i++)   {
        cin>>st1>>st2>>t;
        g[st1][st2]=t;
        g[st2][st1]=t;
    }
    set<string>::iterator it1,it2;
//    for (it1=ss.begin();it1!=ss.end();it1++)
//        cout<<*it1<<' ';
//    cout<<endl;
    for (it1=ss.begin();it1!=ss.end();it1++)  {
        d[*it1]=INF;
        used[*it1]=false;
        for (it2=ss.begin();it2!=ss.end();it2++)  {
            if (g[*it1][*it2]>0)    continue;
            if (*it1==*it2) g[*it1][*it2]=0;
            else    g[*it1][*it2]=INF;
        }
    }
    dijkstra(be);
    cout<<rnum<<' '<<shts<<' '<<maxhappy<<' '<<(int)avghappy<<endl;
    if (!ans.empty())   {
        cout<<ans.top();
        ans.pop();
    }
    while (!ans.empty())    {
        cout<<"->"<<ans.top();
        ans.pop();
    }
    cout<<endl;
    return 0;
}

void dijkstra(string be) {
    set<string>::iterator it3;
    d[be]=0;
    used["ROM"]=true;
    while (true)    {
        string v="000";
        for (it3=ss.begin();it3!=ss.end();it3++)  {
            if (!used[*it3]&&(v=="000"||d[*it3]<d[v]))
                v=*it3;
        }
        if (v=="000")   break;
        used[v]=true;
        //cout<<v<<endl;
        for (it3=ss.begin();it3!=ss.end();it3++)    {
            //cout<<*it3<<'\t'<<d[*it3]<<'\t';
            //cout<<d[v]<<'\t'<<g[v][*it3]<<endl;
            if (d[*it3]>=d[v]+g[v][*it3])    {
                d[*it3]=d[v]+g[v][*it3];
                if (v!=*it3)
                    path[*it3]=v;
                if (*it3=="ROM"&&d[*it3]<=shts)    {
                    if (d[*it3]==shts)  rnum++;
                    else    rnum=1;
                    int cnt=0,tth=0;
                    double tavgh=0;
                    stack<string> sk;
                    string tst=*it3;
                    while (tst!=be)    {
                        tth+=happy[tst];
                        sk.push(tst);
                        tst=path[tst];
                        cnt++;
                    }
                    sk.push(be);
                    tavgh=1.0*tth/cnt;
                    if (d[*it3]<shts)   {
                        shts=d[*it3];
                        ans=sk;
                        avghappy=tavgh;
                        maxhappy=tth;
                    }
                    else if (d[*it3]==shts) {
                        if (tth>maxhappy)   {
                            maxhappy=tth;
                            avghappy=tavgh;
                            ans=sk;
                        }
                        else if (tth==maxhappy) {
                            if (tavgh>avghappy) {
                                avghappy=tavgh;
                                ans=sk;
                            }
                        }
                    }
                }
            }
        }
    }
}
