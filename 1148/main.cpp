#include <bits/stdc++.h>
#define N 105
using namespace std;
int a[N];
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)   {              //����i��j������
        for (int j=i+1;j<=n;j++)    {
            vector<int> v,se(n+1,1);          //se�洢��ǰ�����µ���ʵ�����-1��ʾi�����ˣ�1��ʾi�Ǻ���
            se[i]=se[j]=-1;
            for (int k=1;k<=n;k++)
                if (a[k]*se[abs(a[k])]<0)
                    v.push_back(k);
            if ((int)v.size()==2&&(se[v[0]]+se[v[1]]==0))  {printf("%d %d\n",i,j);return 0;}
        }
    }
    printf("No Solution\n");
    return 0;
}
