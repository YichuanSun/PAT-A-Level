#include <bits/stdc++.h>
using namespace std;
struct num{
    int g,s,k;
};
num a,b,c;
int main()  {
    scanf("%d.%d.%d",&a.g,&a.s,&a.k);
    scanf("%d.%d.%d",&b.g,&b.s,&b.k);
    c.k=(a.k+b.k)%29;
    c.s+=(a.k+b.k)/29;
    int t=c.s;
    c.s=(c.s+a.s+b.s)%17;
    c.g+=(t+a.s+b.s)/17+a.g+b.g;
    printf("%d.%d.%d\n",c.g,c.s,c.k);
    return 0;
}
