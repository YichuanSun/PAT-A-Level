#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x7FFFFFFF;
const int maxn = 5e2 + 10;
int n;
double C, D, d, maxdis, mincost = INF;

struct point
{
    double p, d;
    void read()
    {
        scanf("%lf%lf", &p, &d);
    }
    bool operator<(const point&a)const
    {
        return d == a.d ? p < a.p : d < a.d;
    }
} a[maxn];

void dfs(int x, double cost, double rest)
{
    maxdis = max(maxdis, a[x].d + C*d);     //每次到站加满油后跑的距离，也就是最远距离
    int minx = x;
    for (int i = x + 1; i < n; i++)
    {
        if (a[i].d - a[x].d <= C*d)         //如果能够行驶到第i站
        {
            if (a[i].p <= a[x].p)           //如果第i站油价比当前站更便宜
            {
                double k = (a[i].d - a[x].d) / d;       //k是从x站到i站所需的油数
                if (k > rest)                           //如果靠当前剩下的油到不了第i站
                    dfs(i, cost + (k - rest)*a[x].p, 0);//就在x站加够正好到第i站的油，行驶到第i站正好没油，dfs
                else                                    //如果到得了第i站
                    dfs(i, cost, rest - k);             //就计算更新剩余油，到第i站继续dfs
                return;
            }       //路上碰到第一个油价更便宜的，这个if就return，这段函数就终止了。如果没碰到，就继续下面的操作
                    //如果第i站油价比当前站更贵
            if (minx == x || a[i].p < a[minx].p)        //记录除当前站外油价最便宜的那一站，或者现在的第i站
                minx = i;
        }
    }
        //如果能运行到这里，上面的循环结束后，就意味着当前站点是现在加满油能到达的站点油费当中最便宜的
    if (a[x].d + C*d >= D)      //如果当前站加满油就能到终点站
    {
        if ((D - a[x].d) / d - rest >= 0)
            mincost = min(mincost, cost + ((D - a[x].d) / d - rest)*a[x].p);
    }
    if (minx > x)   //如果下一个次便宜的站点在当前站点之后
    {
        double k = (C - rest)*a[x].p;
        dfs(minx, cost + k, C - (a[minx].d - a[x].d) / d);      //就在当前站点加满油，继续行驶到minx站点
    }
}

int main()
{
    scanf("%lf%lf%lf%d", &C, &D, &d, &n);
    for (int i = 0; i < n; i++)
        a[i].read();
    sort(a, a + n);
    if (a[0].d > 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    dfs(0, 0, 0);
    if (maxdis < D)     //从第一个站点出发
        printf("The maximum travel distance = %.2lf\n", maxdis);
    else
        printf("%.2lf\n", mincost);
    return 0;
}
