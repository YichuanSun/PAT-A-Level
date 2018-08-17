#include <bits/stdc++.h>
using namespace std;
bool isPrime(int q);
int main()  {
    int n,d;
    while (scanf("%d",&n)&&n>0) {
        char st[100],*stop,st1[100];
        memset(st,0,sizeof(st));
        //memset(st1,0,sizeof(st1));
        scanf("%d",&d);
        if (!isPrime(n))    {
            cout<<"No\n";
            continue;
        }
        int cnt=0;
        //itoa(n,st1,d);
        //for (int i=0;i<strlen(st1);i++) printf("%d\n",st1[i]);
        while (n)   {
            st[cnt++]=n%d+'0';
            n/=d;
        }
        //cout<<"OK"<<endl;
        //for (int i=0;i<cnt;i++) printf("%d\n",st[i]);
        int rp=strtol(st,&stop,d);
        if (isPrime(rp)) cout<<"Yes\n";
        else    cout<<"No\n";
    }
    return 0;
}

bool isPrime(int q) {
    if (q==1||q==0) return false;
    int sq=sqrt(q);
    for (int i=2;i<=sq;i++)
        if (q%i==0) return false;
    return true;
}
