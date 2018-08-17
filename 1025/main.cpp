#include <bits/stdc++.h>
using namespace std;
struct info {
    string num;
    int f_rank,l_num,l_rank,score;
};
bool cmp(info a,info b) {
    if (a.score==b.score)
        return a.num<b.num;
    return a.score>b.score;
}
vector<info> infos[103];
int main()  {
    int n,k,cnt=1,sum=0;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&k);
        sum+=k;
        for (int i=1;i<=k;i++)   {
            info ss;
            cin>>ss.num;
            cin>>ss.score;
            ss.l_num=cnt;
            infos[cnt].push_back(ss);
        }
        sort(infos[cnt].begin(),infos[cnt].end(),cmp);
        for (int i=0;i<infos[cnt].size();i++)   {
            if (i==0)   infos[cnt][i].l_rank=i+1;
            else if (infos[cnt][i].score!=infos[cnt][i-1].score)  infos[cnt][i].l_rank=i+1;
            else if (infos[cnt][i].score==infos[cnt][i-1].score)  infos[cnt][i].l_rank=infos[cnt][i-1].l_rank;
            infos[101].push_back(infos[cnt][i]);
        }
        cnt++;
    }
    sort(infos[101].begin(),infos[101].end(),cmp);
    for (int i=0;i<infos[101].size();i++)   {
        if (i==0)   infos[101][i].f_rank=i+1;
        else if (infos[101][i].score!=infos[101][i-1].score)  infos[101][i].f_rank=i+1;
        else if (infos[101][i].score==infos[101][i-1].score)  infos[101][i].f_rank=infos[101][i-1].f_rank;
    }
    cout<<sum<<endl;
    for (int i=0;i<infos[101].size();i++)   {
        cout<<infos[101][i].num<<' ';
        cout<<infos[101][i].f_rank<<' ';
        cout<<infos[101][i].l_num<<' ';
        cout<<infos[101][i].l_rank<<endl;
    }
    return 0;
}
