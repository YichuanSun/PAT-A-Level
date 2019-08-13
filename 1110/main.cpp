#include <bits/stdc++.h>
#define N 105
using namespace std;
bool lo[N];
typedef pair<int,int> pii;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
vector<pii> vpi;
queue<bt*> qb;
int last,n,root,a,b;
bt* buildTree(int root)    {
    if (root==-1)    return nullptr;
    bt* nw=new bt;
    nw->data=root;
    nw->lc=buildTree(vpi[root].first);
    nw->rc=buildTree(vpi[root].second);
    return nw;
}
void levelTraversal(bt* tr) {
    if (tr==nullptr)    return;
    int cnt=0;
    qb.push(tr);
    while (!qb.empty()) {
        bt *nw=qb.front();qb.pop();
        //if (nw) printf("cnt=%d %d\n",cnt,nw->data);
        if (nw) {cnt++;qb.push(nw->lc);qb.push(nw->rc);}
        if (nw==nullptr)    {
            if (cnt==n) printf("YES %d\n",last);
            else printf("NO %d\n",root);
            return;
        }
        else last=nw->data;
    }
}
int main()  {
    cin>>n;
    for (int i=0;i<n;i++)   {       //最后换了流输入输出才搞好，真是无聊
        string l,r;
        cin>>l>>r;
        if (l=="-")
            if (r=="-") a=-1,b=-1;
            else a=-1,b=stoi(r);
        else
            if (r=="-") a=stoi(l),b=-1;
            else a=stoi(l),b=stoi(r);
        vpi.push_back({a,b});
        if (0<=a)   lo[a]=true;
        if (0<=b)   lo[b]=true;
    }
    for (int i=0;i<n;i++)
        if (!lo[i]) {root=i;break;}
    bt* tree=buildTree(root);
    levelTraversal(tree);
    return 0;
}
