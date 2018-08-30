#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b);
int main()  {
    int n;
    long long fz=0,fm=1,nu,de;
    cin>>n;
    for (int i=0;i<n;i++)   {
        scanf("%lld/%lld",&nu,&de);
        long long gys=gcd(fm,de);
        long long gbs=fm*de/gys;
        fz=fz*gbs/fm+nu*gbs/de;
        fm=gbs;
        long long t=gcd(fz,fm);
        fz=fz/t;
        fm=fm/t;
    }
    long long itg=fz/fm;
    fz=fz-fm*itg;
    if (fz!=0)  {
        for (int i=2;i<=fm&&i<=fz;i++)    {
            while (fm%i==0&&fz%i==0)   {
                fm/=i;
                fz/=i;
            }
        }
        if (itg!=0) printf("%lld %lld/%lld\n",itg,fz,fm);
        else    printf("%lld/%lld\n",fz,fm);
    }
    else    printf("%ld\n",itg);
    return 0;
}

long long gcd(long long a,long long b)    {
    if (a%b==0) return b;
    return gcd(b,a%b);
}
