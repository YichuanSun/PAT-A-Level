#include <bits/stdc++.h>
#define N 505
#define INF 100000005
using namespace std;
typedef pair<int,int> pii;
pii g[N][N];    //����1���мǣ���������ʼ���뽫ÿ������ΪINF
int n,m,d[N],dispred[N],t[N],nodenum[N],timepred[N];
bool used[N];
void dijkstraDis(int be);
void dijkstraTime(int be);
vector<int> getPath(int a[],int ed);
int main()  {
    pii tp={INF,INF};
    fill(g[0],g[0]+N*N,tp);     //��ͼg�ĳ�ʼ��
    int v1,v2,l,ti,sp,be,en;    //�м����
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>v1>>v2>>sp>>l>>ti;
        g[v1][v2]={l,ti};
        if (sp==0)  g[v2][v1]={l,ti};   //��ʼ��˫���
    }
    cin>>be>>en;                //��� �յ�
    dijkstraDis(be);            //�Ծ���������·
    dijkstraTime(be);           //��ʱ��������·
    vector<int> dip=getPath(dispred,en);    //·����ԭ����̾���
    vector<int> tip=getPath(timepred,en);   //·����ԭ�����ʱ��
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

void dijkstraDis(int be)   {        //�������·������Ҫ��һ�����������¼ÿ���ڵ�������ֵ��һ��һά��������
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
                t[u]=t[v]+g[v][u].second;               //��Ҫ�������
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
    return vi;  //·���ķ�����û������
}
