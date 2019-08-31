#include <bits/stdc++.h>
#define N 505
#define INF 100000005
using namespace std;
typedef pair<int,int> pii;
pii g[N][N];    //错因1，切记，易忘：初始化须将每条边设为INF
int n,m,d[N],dispred[N],t[N],nodenum[N],timepred[N];
bool used[N];
void dijkstraDis(int be);
void dijkstraTime(int be);
vector<int> getPath(int a[],int ed);
int main()  {
    pii tp={INF,INF};
    fill(g[0],g[0]+N*N,tp);     //对图g的初始化
    int v1,v2,l,ti,sp,be,en;    //中间变量
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>v1>>v2>>sp>>l>>ti;
        g[v1][v2]={l,ti};
        if (sp==0)  g[v2][v1]={l,ti};   //初始化双向边
    }
    cin>>be>>en;                //起点 终点
    dijkstraDis(be);            //对距离进行最短路
    dijkstraTime(be);           //对时间进行最短路
    vector<int> dip=getPath(dispred,en);    //路径还原的最短距离
    vector<int> tip=getPath(timepred,en);   //路径还原的最短时间
    printf("Distance = %d",d[en]);
    if (dip==tip)   printf("; Time = %d: ",t[en]);
    else {
        printf(": ");
        for (int i=(int)dip.size()-1;i>=0;i--)  {
            printf("%d",dip[i]);
            if (i!=0)   printf(" -> ");
        }
        printf("\nTime = %d: ",t[en]);
    }
    for (int i=(int)tip.size()-1;i>=0;i--)  {
        printf("%d",tip[i]);
        if (i!=0)   printf(" -> ");
    }
    printf("\n");
    return 0;
}

void dijkstraDis(int be)   {        //条件最短路，就需要开一个辅助数组记录每个节点条件的值，一般一维数组足矣
    fill(d,d+N,INF);
    fill(used,used+N,false);
    fill(dispred,dispred+N,-2);
    d[be]=0;
    dispred[be]=-1;
    while (true)    {
        int v=-1;
        for (int u=0;u<n;u++)
            if (!used[u]&&(v==-1||d[u]<d[v]))   v=u;
        if (v==-1)  break;
        used[v]=true;
        for (int u=0;u<n;u++)   {
            if (d[u]>d[v]+g[v][u].first)    {
                d[u]=d[v]+g[v][u].first;
                dispred[u]=v;
                t[u]=t[v]+g[v][u].second;               //不要忘了这句
            }
            else if (d[u]==d[v]+g[v][u].first&&t[u]>t[v]+g[v][u].second)    {
                t[u]=t[v]+g[v][u].second;
                dispred[u]=v;
            }
        }
    }
}

void dijkstraTime(int be)   {
    fill(t,t+N,INF);
    fill(used,used+N,false);
    fill(timepred,timepred+N,-2);
    fill(nodenum,nodenum+N,0);
    t[be]=0;
    timepred[be]=-1;
    while (true)    {
        int v=-1;
        for (int u=0;u<n;u++)
            if (!used[u]&&(v==-1||t[u]<t[v]))   v=u;
        if (v==-1)  break;
        used[v]=true;
        for (int u=0;u<n;u++)   {
            if (t[u]>t[v]+g[v][u].second)    {
                t[u]=t[v]+g[v][u].second;
                timepred[u]=v;
                nodenum[u]=nodenum[v]+1;
            }
            else if (t[u]==t[v]+g[v][u].second&&nodenum[u]>nodenum[v]+1) {
                timepred[u]=v;
                nodenum[u]=nodenum[v]+1;
            }
        }
    }
}

vector<int> getPath(int a[],int ed)   {
    vector<int> vi;
    for (;ed!=-1;ed=a[ed]) vi.push_back(ed);
    return vi;  //路径的反向，我没有逆置
}
