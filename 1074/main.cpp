#include <bits/stdc++.h>
using namespace std;
int node[100005][2],li[100005];
int main()  {
    int add,n,k,ad,da,ne;
    scanf("%d%d%d",&add,&n,&k);
    for (int i=0;i<n;i++)   {
        scanf("%d%d%d",&ad,&da,&ne);
        node[ad][0]=da;
        node[ad][1]=ne;
    }
    int pp=add,i=0;
    while (pp!=-1)   {
        li[i++]=pp;
        pp=node[pp][1];
    }
    li[i]=-1;
    int cc=0;
    while(cc+k<=i) {
        reverse(li+cc,li+cc+k);
        cc+=k;
    }
    for (int j=0;j<i-1;j++)
        printf("%05d %d %05d\n",li[j],node[li[j]][0],li[j+1]);
    printf("%05d %d -1\n",li[i-1],node[li[i-1]][0]);
    return 0;
}
