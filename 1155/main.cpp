#include <bits/stdc++.h>
#define N 1005
using namespace std;
void dfs(int now);
int a[N],n,mx=1,mn=1;
vector<int> v;
int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    v.push_back(a[1]);
    dfs(1);
    for (int i=2;i<=n;i++)    {     //从2开始，检测i/2，而不是i*2，这样不需要处理下标越界，简单了很多
        if (a[i/2]>a[i])    mn=0;
        if (a[i/2]<a[i])    mx=0;
    }
    if (mn==0&&mx==1)   printf("Max Heap\n");
    else printf("%s\n",(mn==1&&mx==0)?"Min Heap":"Not Heap");
    return 0;
}

void dfs(int now)   {
    if (2*now>n&&2*now+1>n) {   //如果当前节点的（可能的）子节点会超过n，也就是当前节点如果不存在
        if (now<=n) {           //说明该路径已经到最后一层，如果now仍未越界，则可开始打印路径
            for (int i=0;i<(int)v.size();i++)
                printf("%d%c",v[i],i!=(int)v.size()-1?' ':'\n');
        }       //外部会自动pop，在搜到最深路径时不用清除v中所有数据
    }
    else {
        v.push_back(a[2*now+1]);
        dfs(2*now+1);
        v.pop_back();               //回溯，记住
        v.push_back(a[2*now]);
        dfs(2*now);
        v.pop_back();
    }
}
