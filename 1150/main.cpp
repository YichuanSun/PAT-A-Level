#include <bits/stdc++.h>
#define N 205
#define Max 1000000
using namespace std;
int g[N][N];
int main()  {
    int n,m,k,ans=Max,ansi=Max;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)   {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=c;
        g[b][a]=c;
    }
    scanf("%d",&k);
    for (int z=1;z<=k;z++) {
        printf("Path %d: ",z);
        int tn,spot[N]={0},ta[N],na=0,is_cycle=0;
        scanf("%d",&tn);
        for (int i=0;i<tn;i++)   scanf("%d",&ta[i]);
        int i=0,sum=0;
        while (i<tn)    {
            spot[ta[i]]++;
            if (i+1<tn) {
                if (g[ta[i]][ta[i+1]]) {
                    sum+=g[ta[i]][ta[i+1]];
                }
                else {na=1;break;}
            }
            if (i+1==tn)  {  //说明当前是最后一个元素
                if (ta[0]==ta[i])   {       //判断成环
                    is_cycle=1;
                }
            }
            i++;
            if (na) break;
        }
        if (!na)    {

            printf("%d ",sum);
            int neg=0,p2=0,pn=0;
            set<int> si;
            for (int i=1;i<=n;i++)   {
                if (spot[i]>0)  si.insert(i);
                if (spot[i]==0)  neg=1;
                if (spot[i]>2) pn++;
                if (spot[i]==2) p2++;
            }
            if (is_cycle&&neg==0&&pn==0&&p2==1&&spot[ta[0]]==2&&(int)si.size()==n)  {
                if (sum<ans)    {
                    ans=sum;
                    ansi=z;
                }
                printf("(TS simple cycle)\n");
            }
            else if (is_cycle&&neg==0&&(pn>0||p2>1)&&(int)si.size()==n) {
                if (sum<ans)    {
                    ans=sum;
                    ansi=z;
                }
                printf("(TS cycle)\n");
            }
            else
                printf("(Not a TS cycle)\n");
        }
        else printf("NA (Not a TS cycle)\n");
    }
    printf("Shortest Dist(%d) = %d\n",ansi,ans);
    return 0;
}
