#include <bits/stdc++.h>
#define N 1005
using namespace std;
void dfs(int a[],int be);
void postorder(int a[],int b);
int a[N],n,m;
bool mxh=1,mnh=1;
int main()  {
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++)   {
        for (int i=1;i<=n;i++)   scanf("%d",a+i);
        dfs(a,1);
        if (mxh)    {
            if (!mnh)   printf("Max Heap\n");
            else printf("Not Heap\n");
        }
        else if (mnh)   printf("Min Heap\n");
        else printf("Not Heap\n");
        printf("%d %d\n",mxh,mnh);
        postorder(a,1);
        printf("\n");
        mxh=mnh=true;
    }
    return 0;
}

void postorder(int a[],int b)    {
    if (2*b>n&&2*b+1>n) {
        if (b<=n)   printf("%d ",a[b]);
        return;
    }
    postorder(a,2*b);
    postorder(a,2*b+1);
    printf("%d ",a[b]);
}

void dfs(int a[],int be)    {
    if (be>n)   return;
    if (2*be<=n)   {
        if (a[2*be]>a[be])  mxh=0;
        else if (a[2*be]<a[be]) mnh=0;
        dfs(a,2*be);
    }
    if (2*be+1<=n)  {
        if (a[2*be+1]>a[be])    mxh=0;
        else if (a[2*be+1]<a[be])  mnh=0;
        dfs(a,2*be+1);
    }
}
