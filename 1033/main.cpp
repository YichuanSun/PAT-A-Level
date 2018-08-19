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
    maxdis = max(maxdis, a[x].d + C*d);     //ÿ�ε�վ�����ͺ��ܵľ��룬Ҳ������Զ����
    int minx = x;
    for (int i = x + 1; i < n; i++)
    {
        if (a[i].d - a[x].d <= C*d)         //����ܹ���ʻ����iվ
        {
            if (a[i].p <= a[x].p)           //�����iվ�ͼ۱ȵ�ǰվ������
            {
                double k = (a[i].d - a[x].d) / d;       //k�Ǵ�xվ��iվ���������
                if (k > rest)                           //�������ǰʣ�µ��͵����˵�iվ
                    dfs(i, cost + (k - rest)*a[x].p, 0);//����xվ�ӹ����õ���iվ���ͣ���ʻ����iվ����û�ͣ�dfs
                else                                    //��������˵�iվ
                    dfs(i, cost, rest - k);             //�ͼ������ʣ���ͣ�����iվ����dfs
                return;
            }       //·��������һ���ͼ۸����˵ģ����if��return����κ�������ֹ�ˡ����û�������ͼ�������Ĳ���
                    //�����iվ�ͼ۱ȵ�ǰվ����
            if (minx == x || a[i].p < a[minx].p)        //��¼����ǰվ���ͼ�����˵���һվ���������ڵĵ�iվ
                minx = i;
        }
    }
        //��������е���������ѭ�������󣬾���ζ�ŵ�ǰվ�������ڼ������ܵ����վ���ͷѵ�������˵�
    if (a[x].d + C*d >= D)      //�����ǰվ�����;��ܵ��յ�վ
    {
        if ((D - a[x].d) / d - rest >= 0)
            mincost = min(mincost, cost + ((D - a[x].d) / d - rest)*a[x].p);
    }
    if (minx > x)   //�����һ���α��˵�վ���ڵ�ǰվ��֮��
    {
        double k = (C - rest)*a[x].p;
        dfs(minx, cost + k, C - (a[minx].d - a[x].d) / d);      //���ڵ�ǰվ������ͣ�������ʻ��minxվ��
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
    if (maxdis < D)     //�ӵ�һ��վ�����
        printf("The maximum travel distance = %.2lf\n", maxdis);
    else
        printf("%.2lf\n", mincost);
    return 0;
}
