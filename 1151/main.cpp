#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int> pos;          //pos是中序遍历节点值对应在中序序列的节点下标
vector<int> in, pre;
void lca(int inl, int inr, int preRoot, int a, int b) { //preroot是当前根节点在先序中的次序，a,b,分别是需要判断的点的值
    if (inl > inr) return;      //inl和inr划定左右范围
    int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];     //pre存先序序列
    if (aIn < inRoot && bIn < inRoot)           //inroot是先序序列的当前根节点在中序序列中的坐标，两点都在根左边
        lca(inl, inRoot-1, preRoot+1, a, b);
    else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))  //两点一左一右
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    else if (aIn > inRoot && bIn > inRoot)      //两点都在右边
        lca(inRoot+1, inr, preRoot+1+(inRoot-inl), a, b);   //这个坐标的变幻实在顶不住啊，先序后序我都忘光了
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
//        dein[in[i]]=i;          //存储in中元素位置
//    }
//    for (int i=1;i<=n;i++)   {
//        scanf("%d",&pre[i]);
//        depre[pre[i]]=i;        //存储pre中元素位置
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
//                    &&depre[in[j]]<depre[in[mx]])   {       //如果这个点在先序遍历之前
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
