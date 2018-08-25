#include <bits/stdc++.h>
#define N 1005
#define INF 0x7fffffff
using namespace std;
struct en{
    int num,score,rnk;
};
vector<int> ori;
queue<pair<int,int> > tq;
vector<en> ans;
int val[N];
bool cmp1(en a,en b)  {
    return a.score>b.score;
}
bool cmp2(en a,en b)    {
    return a.num<b.num;
}
int main()  {
    int np,ng,t;
    cin>>np>>ng;
    for (int i=0;i<np;i++)  {
        cin>>t;
        ori.push_back(t);
    }
    for (int i=0;i<np;i++)  {
        cin>>t;
        tq.push(make_pair(ori[t],t));
    }
    int cnt=0;
    while (tq.size()!=1)    {
        int i=0,ss=tq.size();
        while (i<ss)    {
            int be=i,mx=0,num=0;
            queue<pair<int,int> > tpq;
            for (;i<ss&&i<be+ng;i++)  {
                pair<int,int> ttmp=tq.front();
                if (ttmp.first>mx)    {
                    mx=ttmp.first;
                    num=ttmp.second;
                }
                tpq.push(ttmp);
                tq.pop();
            }
            while (!tpq.empty())    {
                if (tpq.front().first!=mx)
                    val[tpq.front().second]=cnt;
                else    {
                    val[tpq.front().second]=INF;
                    tq.push(tpq.front());
                }
                tpq.pop();
            }
        }
        cnt++;
    }
    for (int i=0;i<np;i++)  if (val[i]==INF)    val[i]=cnt;
    for (int i=0;i<np;i++)  {
        en nnw;
        nnw.num=i,nnw.score=val[i],nnw.rnk=0;
        ans.push_back(nnw);
    }
    sort(ans.begin(),ans.end(),cmp1);
    for (unsigned i=0;i<ans.size();i++) {
        if (i==0)   ans[i].rnk=1;
        else if (ans[i].score==ans[i-1].score)
            ans[i].rnk=ans[i-1].rnk;
        else if (ans[i].score<ans[i-1].score)
            ans[i].rnk=i+1;
    }
    sort(ans.begin(),ans.end(),cmp2);
    cout<<ans[0].rnk;
    for (unsigned i=1;i<ans.size();i++)
        cout<<' '<<ans[i].rnk;
    cout<<endl;
    return 0;
}
