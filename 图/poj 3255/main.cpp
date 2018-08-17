#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_V 5005
#define INF 10000000
using namespace std;
void dijkstra(int s);
struct edge{
    int cost,to;
    edge(int a,int b)   {to=a,cost=b;}
};
typedef pair<int,int> P;
vector<edge> G[MAX_V];
int dist1[MAX_V],dist2[MAX_V];
int main()  {
    int N,R,a,b,c;
    cin>>N>>R;
    for (int i=0;i<R;i++)    {
        scanf("%d %d %d",&a,&b,&c);
        G[a].push_back(edge(b,c));
        G[b].push_back(edge(a,c));
    }
    dijkstra(1);
    cout<<dist2[N]<<endl;
    return 0;
}
void dijkstra(int s) {
    priority_queue<P,vector<P>,greater<P> >    que;
    fill(dist1,dist1+MAX_V,INF);
    fill(dist2,dist2+MAX_V,INF);
    dist1[s]=0;
    que.push(P(0,s));
    while(!que.empty()) {
        P p=que.top();que.pop();    //�õ�p��Ϊ��ǰ��ʣ�������ĵ㣬������pair��ʾ��
        int d=p.first,v=p.second;     //d��ʾ��ǰ������ʼ������·���ȣ�v��ʾ�����
        if (dist2[v]<d)   continue;       ////?
        for(int i=0;i<G[v].size();i++)  {       //������������v�������ڱߣ��Ը���d
            edge &e=G[v][i];        ////
            int d2=d+e.cost;
            if (d2<dist1[e.to])  {
                swap(dist1[e.to],d2);
                que.push(P(dist1[e.to],e.to));
            }
            if (d2>dist1[e.to]&&d2<dist2[e.to]) {
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
}
