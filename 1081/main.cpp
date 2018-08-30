#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b);
int main()  {
    int n;
    int fz=0,fm=1,nu,de;
    cin>>n;
    for (int i=0;i<n;i++)   {
        scanf("%d/%d",&nu,&de);
        int gys=gcd(fm,de);
        int gbs=fm*de/gys;
        fz=fz*gbs/fm+nu*gbs/de;
        fm=gbs;
    }
    int itg=fz/fm;
    fz=fz-fm*itg;
    if (fz!=0)  {
        for (int i=2;i<=fm&&i<=fz;i++)    {
            while (fm%i==0&&fz%i==0)   {
                fm/=i;
                fz/=i;
            }
        }
        if (itg!=0) printf("%d %d/%d\n",itg,fz,fm);
        else    printf("%d/%d\n",fz,fm);
    }
    else    printf("%d\n",itg);
    return 0;
}

int gcd(int a,int b)    {
    if (a%b==0) return b;
    return gcd(b,a%b);
}
