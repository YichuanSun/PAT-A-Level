#include <bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> g[N];
queue<int> que;
pair<int,int> ans[N];
int level[N],le[N],cnt;
void bfs(int n);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,tmp,k;
    double p,r,sum=0;
    cin>>n>>p>>r;
    for (int i=0;i<n;i++)   {
        cin>>tmp;
        if (tmp==0) {
            g[i].push_back(tmp);
            cin>>tmp;
            g[i].push_back(tmp);
        }
        else    {
            for (int j=0;j<tmp;j++){
                cin>>k;
                g[i].push_back(k);
            }
        }
    }
    bfs(0);
    for (int q=0;q<cnt;q++)
        sum+=1.0*ans[q].second*p*pow(1.0+0.01*r,le[ans[q].first]);
    cout.setf(ios::fixed);
    cout<<setprecision(1)<<sum<<endl;
    return 0;
}

void bfs(int n) {
    que.push(n);
    level[0]=1;
    int k=0;
    while (!que.empty())    {
        int tp=que.front();
        que.pop();
        level[k]--;
        for (unsigned j=0;j<g[tp].size();j++)   {
            if (g[tp][j])    {
                que.push(g[tp][j]);
                level[k+1]++;
                le[g[tp][j]]=k+1;
            }
            else    {
                ans[cnt++]=(make_pair(tp,g[tp][1]));
                break;
            }
        }
        if (level[k]==0)    k++;
    }
}
