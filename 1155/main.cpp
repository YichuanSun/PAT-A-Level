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
    for (int i=2;i<=n;i++)    {     //��2��ʼ�����i/2��������i*2����������Ҫ�����±�Խ�磬���˺ܶ�
        if (a[i/2]>a[i])    mn=0;
        if (a[i/2]<a[i])    mx=0;
    }
    if (mn==0&&mx==1)   printf("Max Heap\n");
    else printf("%s\n",(mn==1&&mx==0)?"Min Heap":"Not Heap");
    return 0;
}

void dfs(int now)   {
    if (2*now>n&&2*now+1>n) {   //�����ǰ�ڵ�ģ����ܵģ��ӽڵ�ᳬ��n��Ҳ���ǵ�ǰ�ڵ����������
        if (now<=n) {           //˵����·���Ѿ������һ�㣬���now��δԽ�磬��ɿ�ʼ��ӡ·��
            for (int i=0;i<(int)v.size();i++)
                printf("%d%c",v[i],i!=(int)v.size()-1?' ':'\n');
        }       //�ⲿ���Զ�pop�����ѵ�����·��ʱ�������v����������
    }
    else {
        v.push_back(a[2*now+1]);
        dfs(2*now+1);
        v.pop_back();               //���ݣ���ס
        v.push_back(a[2*now]);
        dfs(2*now);
        v.pop_back();
    }
}
