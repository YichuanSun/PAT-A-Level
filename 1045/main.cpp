#include <bits/stdc++.h>
#define N 10005
using namespace std;
int stripe[N],like[205],big[N];
int main()  {
    int n,n_like,tmp,num,Max;
    cin>>n;
    cin>>n_like;
    for (int i=1;i<=n_like;i++) {
        cin>>tmp;
        like[tmp]=i;
    }
    cin>>num;
    for (int i=1;i<=num;i++) {
        cin>>tmp;
        stripe[i]=like[tmp];
    }
    for (int i=1;i<=num;i++)    {
        if (stripe[i]==0)   continue;
        Max=0;
        for (int j=1;j<=stripe[i];j++)  {
            if (Max<=big[j])    Max=big[j];
        }
        big[stripe[i]]=Max+1;
    }
    Max=0;
    for (int i=n_like;i>=1;i--)
        if (big[i]>Max) Max=big[i];
    cout<<Max<<endl;
    return 0;
}








//17分，一个wa，两个tle
//#include <bits/stdc++.h>
//#define N 10005
//using namespace std;
//map<int,int> color;
//int ans,stp[N];
//int n,m,L,t;
//void dfs(int i,int len);
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cin>>n>>m;
//    for (int i=1;i<=m;i++)   {
//        cin>>t;
//        color[t]=i;
//    }
//    for (int i=n;i<m;i++)   color[i]=0;
//    cin>>L;
//    for (int i=0;i<L;i++)   cin>>stp[i];
//    int s=0;
//    for (s=0;s<L;s++)
//        if (color[stp[s]]!=0)
//            break;
//    if (s==L)   {
//        cout<<0<<endl;
//        return 0;
//    }
//    dfs(s,1);
//    cout<<ans<<endl;
//    return 0;
//}
//
//void dfs(int i,int len)  {
//    ans=max(ans,len);
//    for (int j=i+1;j<L;j++) {
//        if (color[stp[j]]==0)    continue;
//        else if (color[stp[j]]<color[stp[i]]) continue;
//        else    {
//            dfs(j,len+1);
//        }
//    }
//}
