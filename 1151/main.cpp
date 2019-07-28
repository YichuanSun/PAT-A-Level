#include <bits/stdc++.h>
#define N 10005
using namespace std;
int in[N],pre[N],dein[N],depre[N];
int main()  {
    int n,m;
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++)   {
        scanf("%d",&in[i]);
        dein[in[i]]=i;          //存储in中元素位置
    }
    for (int i=1;i<=n;i++)   {
        scanf("%d",&pre[i]);
        depre[pre[i]]=i;        //存储pre中元素位置
    }
    for (int i=0;i<m;i++)   {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a<=0||a>10000)   {
            if (b<=0||b>10000)
                printf("ERROR: %d and %d are not found.\n",a,b);
            else
                printf("ERROR: %d is not found.\n",a);
            continue;
        }
        else if (b<=0||b>10000)  {printf("ERROR: %d is not found.\n",b);continue;}
        int mn=min(dein[a],dein[b]);
        int mx=max(dein[a],dein[b]),ans=depre[mn];
        if (dein[a]==0) {
            if (dein[b]==0)
                printf("ERROR: %d and %d are not found.",a,b);
            else
                printf("ERROR: %d is not found.",a);
        }
        else if (dein[b]==0)
            printf("ERROR: %d is not found.\n",b);
        else if (mx-mn==1)
            printf("%d is an ancestor of %d.\n",in[mx],in[mn]);
        else {
            for (int j=mn+1;j<mx;j++)   {
                if (depre[in[j]]<depre[in[mn]]
                    &&depre[in[j]]<depre[in[mx]])   {       //如果这个点在先序遍历之前
                    if (depre[in[j]]<depre[in[ans]])    {
                        ans=j;
                    }
                }
            }
            printf("LCA of %d and %d is %d.\n",a,b,in[ans]);
        }
    }
    return 0;
}
