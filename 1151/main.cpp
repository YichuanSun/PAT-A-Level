#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int> pos;          //pos����������ڵ�ֵ��Ӧ���������еĽڵ��±�
vector<int> in, pre;
void lca(int inl, int inr, int preRoot, int a, int b) { //preroot�ǵ�ǰ���ڵ��������еĴ���a,b,�ֱ�����Ҫ�жϵĵ��ֵ
    if (inl > inr) return;      //inl��inr�������ҷ�Χ
    int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];     //pre����������
    if (aIn < inRoot && bIn < inRoot)           //inroot���������еĵ�ǰ���ڵ������������е����꣬���㶼�ڸ����
        lca(inl, inRoot-1, preRoot+1, a, b);
    else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))  //����һ��һ��
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    else if (aIn > inRoot && bIn > inRoot)      //���㶼���ұ�
        lca(inRoot+1, inr, preRoot+1+(inRoot-inl), a, b);   //�������ı��ʵ�ڶ���ס������������Ҷ�������
    else if (aIn == inRoot)
            printf("%d is an ancestor of %d.\n", a, b);
    else if (bIn == inRoot)
            printf("%d is an ancestor of %d.\n", b, a);
}
int main() {
    int m, n, a, b;
    scanf("%d %d", &m, &n);
    in.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (pos[a] == 0 && pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0)
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        else
            lca(1, n, 1, a, b);
    }
    return 0;
}



















//#include <bits/stdc++.h>
//#define N 10005
//using namespace std;
//int in[N],pre[N],dein[N],depre[N];
//int main()  {
//    int n,m;
//    scanf("%d%d",&m,&n);
//    for (int i=1;i<=n;i++)   {
//        scanf("%d",&in[i]);
//        dein[in[i]]=i;          //�洢in��Ԫ��λ��
//    }
//    for (int i=1;i<=n;i++)   {
//        scanf("%d",&pre[i]);
//        depre[pre[i]]=i;        //�洢pre��Ԫ��λ��
//    }
//    for (int i=0;i<m;i++)   {
//        int a,b;
//        scanf("%d%d",&a,&b);
//        if (a<=0||a>10000)   {
//            if (b<=0||b>10000)
//                printf("ERROR: %d and %d are not found.\n",a,b);
//            else
//                printf("ERROR: %d is not found.\n",a);
//            continue;
//        }
//        else if (b<=0||b>10000)  {printf("ERROR: %d is not found.\n",b);continue;}
//        int mn=min(dein[a],dein[b]);
//        int mx=max(dein[a],dein[b]),ans=depre[mn];
//        if (dein[a]==0) {
//            if (dein[b]==0)
//                printf("ERROR: %d and %d are not found.",a,b);
//            else
//                printf("ERROR: %d is not found.",a);
//        }
//        else if (dein[b]==0)
//            printf("ERROR: %d is not found.\n",b);
//        else if (mx-mn==1)
//            printf("%d is an ancestor of %d.\n",in[mx],in[mn]);
//        else {
//            for (int j=mn+1;j<mx;j++)   {
//                if (depre[in[j]]<depre[in[mn]]
//                    &&depre[in[j]]<depre[in[mx]])   {       //�����������������֮ǰ
//                    if (depre[in[j]]<depre[in[ans]])    {
//                        ans=j;
//                    }
//                }
//            }
//            printf("LCA of %d and %d is %d.\n",a,b,in[ans]);
//        }
//    }
//    return 0;
//}
