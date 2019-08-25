#include <bits/stdc++.h>
using namespace std;
struct rbtree{
    int v;
    rbtree *lc=nullptr,*rc=nullptr;
};
rbtree* buildTree(rbtree* p,int da) {   //仅凭先序建树
    if (da==0||p==nullptr)   {
        p=new rbtree;
        p->v=da;
        p->lc=p->rc=nullptr;
        return p;
    }
    else if (abs(da)<=abs(p->v))  p->lc=buildTree(p->lc,da);
    else p->rc=buildTree(p->rc,da);
    return p;
}
bool judgeChild(rbtree* root)   {       //判断是否满足父节点红子节点非红
    if (root==nullptr)  return true;
    if (root->v<0)  {
        if (root->lc!=nullptr&&root->lc->v<0)   return false;
        if (root->rc!=nullptr&&root->rc->v<0)   return false;
    }
    return judgeChild(root->lc)&&judgeChild(root->rc);
}
int getBlack(rbtree* root) {   //返回某个节点的黑色高度，即到达根节点的所有路径中，黑色节点的最大个数
    if (root==nullptr)  return 0;
    int lh=getBlack(root->lc);
    int rh=getBlack(root->rc);
    return root->v>0?max(lh,rh)+1:max(lh,rh);
}
bool judgeHeight(rbtree* root)  {       //判断黑色高度是否满足要求
    if (root==nullptr)  return true;
    int ln=getBlack(root->lc);
    int rn=getBlack(root->rc);
    if (ln!=rn) return false;
    return judgeHeight(root->lc)&&judgeHeight(root->rc);
}
int main()  {
    int n,m,t;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>m;
        rbtree* root=nullptr;
        int tp=0;
        for (int j=0;j<m;j++)   {
            cin>>t;
            if (j==0)   tp=t;
            root=buildTree(root,t);
        }
        if (tp<0||judgeChild(root)==false||judgeHeight(root)==false)        //如果有一个不满足要求就输出否
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
