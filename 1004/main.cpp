#include <bits/stdc++.h>
#define MAX_NODE 105
using namespace std;
const int INF=10005;
map<int,vector<int> >   tree;
int save[MAX_NODE];
void dfs(int start,int level);
int main()  {
    int N,M,K,n1,nt,cnt=0;
    int cle;
    cin>>N>>M;
    cle=N-M;
    for (int i=0;i<M;i++)   {
        cin>>n1>>K;
        for (int j=0;j<K;j++)   {
            cin>>nt;
            tree[n1].push_back(nt);
        }
    }
    dfs(1,0);
    cnt=save[0];
    cout<<save[0];
    for (int i=1;cnt<cle;i++)    {
        cnt+=save[i];
        cout<<' '<<save[i];
    }
    cout<<endl;
    return 0;
}

void dfs(int start,int level)  {
    if (tree[start].empty())    {
        if (save[level]==INF)   save[level]=1;
        else save[level]++;
        return;
    }
    vector<int>::iterator ite=tree[start].begin();
    for (;ite!=tree[start].end();ite++) {
        dfs(*ite,level++);
    }
}


/*下答案错了两个用例


#include <bits/stdc++.h>
#define MAX_NODE 105
using namespace std;
const int INF=10005;
map<int,vector<int> >   tree;
int save[MAX_NODE];
void dfs(int start,int level);
int cnt=1;
int main()  {
    int N,M,K,n1,nt;
    cin>>N>>M;
    fill(save,save+MAX_NODE,0);
    for (int i=0;i<M;i++)   {
        cin>>n1>>K;
        for (int j=0;j<K;j++)   {
            cin>>nt;
            tree[n1].push_back(nt);
        }
    }
    dfs(1,0);
    cout<<save[0];
    for (int i=1;i<cnt;i++)    cout<<' '<<save[i];
    cout<<endl;
    return 0;
}

void dfs(int start,int level)  {
    if (tree[start].empty())    {
        if (save[level]==INF)   save[level]=1;
        else save[level]++;
        return;
    }
    vector<int>::iterator ite=tree[start].begin();
    for (;ite!=tree[start].end();ite++) {
        dfs(*ite,level+1);
    }
    cnt++;
}
*/
