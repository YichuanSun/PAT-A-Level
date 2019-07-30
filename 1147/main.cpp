#include <bits/stdc++.h>
#define N 1005
using namespace std;
void postorder(int a[],int b);
int a[N],n,m;
int main()  {
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++)   {
        for (int i=1;i<=n;i++)   scanf("%d",a+i);
        postorder(a,1);
    }
    return 0;
}

void postorder(int a[],int b)    {
    if (2*b>n&&2*b+1>n) {
        printf("%d ",a[b]);
        return;
    }
    postorder(a,2*b);
    postorder(a,2*b+1);
    printf("%d ",a[b]);
}







