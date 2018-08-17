#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
const int MAX=1005;
float poly[MAX];
int main()
{
    int k,ex;
    float co;
    //fill(poly,poly+MAX,INF);
    scanf("%d",&k);
    while (k--)    {
        scanf(" %d %lf",&ex,&co);
        poly[ex]+=co;
    }
    scanf("%d",&k);
    while (k--)    {
        scanf(" %d %lf",&ex,&co);
        poly[ex]+=co;
    }
    k=0;
    for (int i=0;i<MAX;i++)
        if (poly[i]!=0)   k++;
    printf("%d", k);
    // 项数为0则只输出k，且不带空格
    if(k != 0)
        printf(" ");
    for(int i=MAX-1; i >= 0; i--){
        if(poly[i]!=0.0&&poly[i]!=INF){
            printf("%d ", i);
            printf("%0.1f", poly[i]);
            k--;
            // 输出最后一项后不带空格
            if(k != 0)
                printf(" ");
        }
    }
//    cout<<k;
//    for (int i=MAX-1;i>=0;i--)
//        if (poly[i]!=0)   cout<<' '<<i<<' '<<poly[i];
//    cout<<endl;
    return 0;
}
//下面是错的，就对了两个用例
/*
#include <bits/stdc++.h>
#define SIZE 25
using namespace std;
typedef pair<int,float> term;
vector<term> terms[2];
bool spot[SIZE];
bool cmp(const term a,const term b)  {
    return a.first>b.first;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int k1,k2;
    for (int i=0;i<2;i++)   {
        if (i==0)   cin>>k1;
        if (i==1)   cin>>k2;
        for (int j=0;j<(i==0?k1:k2);j++)   {
            term temp;
            cin>>temp.first;
            cin>>temp.second;
            terms[i].push_back(temp);
        }
    }
    for (int i=0;i<k1;i++)  {
        for (int j=0;j<k2;j++)  {
            if (spot[j]==1) continue;
            if (terms[0][i].first>terms[1][j].first)    break;
            if (terms[0][i].first==terms[1][j].first)   {
                terms[0][i].second+=terms[1][j].second;
                spot[j]=1;
            }
        }
    }
    for (int j=0;j<k2;j++)  {
        if (spot[j]==0&&terms[1][j].second)    {
                terms[0].push_back(terms[1][j]);
                spot[j]=1;
            }
    }
    cout<<terms[0].size();
    sort(terms[0].begin(),terms[0].end(),cmp);
    for (auto a:terms[0])  {
        cout<<' '<<a.first;
        cout<<' '<<a.second;
    }
    cout<<endl;
    return 0;
}
*/
//孩子，不要再为浪费的时间而后悔了
//唯一有意义的，永远是现在！！！
//2018.7.13
/*
4 3 1.5 2 4.9 6 3.1 1 1.1
3 6 1.2 5 7.4 2 9.8

*/
