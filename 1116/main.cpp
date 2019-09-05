#include <bits/stdc++.h>
#define N 10005
using namespace std;
int a[N],ran[N];
bool usd[N],isp[N],exi[N];
void primeCreator() {
    for (int i=2;i<N;i++)   {
        int sp=0;
        for (int j=2;j<=(int)sqrt(i);j++)
            if (i%j==0) {isp[i]=0;sp=1;break;}
        if (sp==0)  isp[i]=1;
    }
}
int main()  {
    primeCreator();
    int n,k,t;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   {cin>>a[i];exi[a[i]]=1;ran[a[i]]=i+1;}
    scanf("%d",&k);
    for (int i=0;i<k;i++)   {
        scanf("%d",&t);
        printf("%04d",t);
        if (!exi[t])    {cout<<": Are you kidding?"<<endl;continue;}
        else if (usd[t]) cout<<": Checked"<<endl;
        else if (t==a[0])
            cout<<": Mystery Award"<<endl;
        else if (isp[ran[t]])    cout<<": Minion"<<endl;
        else cout<<": Chocolate"<<endl;
        usd[t]=1;
    }
    return 0;
}
