#include <bits/stdc++.h>
#define N 100005
using namespace std;
struct Node{
    int now,nex;
    char c;
}node[N];
bool visit[N];
int main()  {
    int s1,s2,n,tnow,tnex;
    char tc;
    scanf("%d%d%d",&s1,&s2,&n);
    for (int i=0;i<n;i++)   {
        scanf("%d %c %d",&tnow,&tc,&tnex);
        node[tnow].now=tnow;
        node[tnow].c=tc;
        node[tnow].nex=tnex;
    }
    while (s1!=-1)  {
        visit[s1]=true;
        s1=node[s1].nex;
    }
    while (s2!=-1)  {
        if (visit[s2])  {
            printf("%05d\n",s2);
            return 0;
        }
        visit[s2]=true;
        s2=node[s2].nex;
    }
    if (s2==-1) cout<<-1<<endl;
    return 0;
}



