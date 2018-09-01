#include <bits/stdc++.h>
using namespace std;
struct ste{
    int num,ge,gi;
    double fi;
    int rk;
    vector<int> coc;
    bool isad=false;
}sl[40005];
int adnum[105],line[405];
vector<int> ans[405];
bool cmp(ste a,ste b)   {
    if (a.fi==b.fi)
        return a.ge>b.ge;
    return a.fi>b.fi;
}
int main()  {
    int n,m,k,tge,tgi,tc;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<m;i++)   scanf("%d",&adnum[i]);
    for (int i=0;i<n;i++)   {
        scanf("%d%d",&tge,&tgi);
        sl[i].num=i;
        sl[i].ge=tge;
        sl[i].gi=tgi;
        sl[i].fi=1.0*(tge+tgi)/2;
        for (int j=0;j<k;j++)   {
            scanf("%d",&tc);
            sl[i].coc.push_back(tc);
        }
    }
    sort(sl,sl+n,cmp);
    //test code
//    for (int i=0;i<n;i++)   {
//        printf("%d:\t%d\t",i,sl[i].num);
//        printf("%d %d ",sl[i].ge,sl[i].gi);
//        for (unsigned j=0;j<sl[i].coc.size();j++)
//            printf(" %d",sl[i].coc[j]);
//        printf("\n");
//    }
    //test code
    sl[0].rk=1;
    for (int i=1;i<n;i++)   {
        if (sl[i].fi==sl[i-1].fi&&sl[i].ge==sl[i-1].ge)
            sl[i].rk=sl[i-1].rk;
        else
            sl[i].rk=i+1;
    }
    for (int i=0;i<n;i++)   {
        if (sl[i].isad==true)   continue;
        for (unsigned j=0;j<sl[i].coc.size();j++)   {
            int slc=sl[i].coc[j];
            if (adnum[slc]>0)   {
                sl[i].isad=true;
                adnum[slc]--;
                ans[slc].push_back(sl[i].num);
                line[slc]=sl[i].rk;
                break;
            }
            else if (adnum[slc]==0&&sl[i].rk==line[slc])    {
                sl[i].isad=true;
                ans[slc].push_back(sl[i].num);
                break;
            }
        }
    }
    for (int i=0;i<m;i++)   {
        if (!ans[i].empty())    {
            sort(ans[i].begin(),ans[i].end());
            printf("%d",ans[i][0]);
        }
        for (unsigned j=1;j<ans[i].size();j++)
            printf(" %d",ans[i][j]);
        printf("\n");
    }
    return 0;
}

























//#include <bits/stdc++.h>
//using namespace std;
//struct sud{
//    int num,ge,rk;
//    double avg;
//}ss[40005];
//int n,m,k;
//vector<int> school[105];
//int line[105];
//bool isadmit[40005];
//bool cmp(int a,int b)   {
//    if (ss[a].avg==ss[b].avg)
//        return ss[a].ge>ss[b].ge;
//    return ss[a].avg>ss[b].avg;
//}
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int ge,gi,ts;
//    cin>>n>>m>>k;
//    for (int i=0;i<m;i++)   cin>>line[i];
//    for (int i=0;i<n;i++)   {
//        cin>>ge>>gi;
//        ss[i].num=i;
//        ss[i].avg=1.0*(ge+gi)/2;
//        ss[i].ge=ge;
//        for (int j=0;j<k;j++)   {
//            cin>>ts;
//            school[ts].push_back(i);
//        }
//    }
//    for (int i=0;i<m;i++)   {
//        sort(school[i].begin(),school[i].end(),cmp);
//        ss[school[i][0]].rk=1;
//        int sz=school[i].size();
//        for (int j=1;j<sz;j++)   {
//            if (ss[school[i][j]].avg==ss[school[i][j-1]].avg) {
//                if (ss[school[i][j]].ge==ss[school[i][j-1]].ge)
//                    ss[school[i][j]].rk=ss[school[i][j-1]].rk;
//                else
//                    ss[school[i][j]].rk=j+1;
//            }
//            else
//                ss[school[i][j]].rk=j+1;
//        }
//        int fate=1;
//        for (int j=0;j<sz;j++)   {
//            if (isadmit[school[i][j]]) continue;
//            if (line[i]>0) {
//                fate=ss[school[i][j]].rk;
//                isadmit[school[i][j]]=true;
//                line[i]--;
//                cout<<school[i][j]<<' ';
//            }
//            else    {
//                if (line[i]<=0&&j==0)    break;
//                else    {
//                    while (j<sz&&fate==ss[school[i][j]].rk){
//                        if (isadmit[school[i][j]]) continue;
//                        isadmit[school[i][j]]=true;
//                        line[i]--;
//                        cout<<school[i][j]<<' ';
//                        j++;
//                    }
//                    break;
//                }
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}
