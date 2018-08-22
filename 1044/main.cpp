#include <bits/stdc++.h>
#define N 100005
using namespace std;
int dias[N],des[N];
vector<int> vec;
int BinSearch(int i,int n,int m);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ret,mi=0x7fffffff;
    cin>>n>>m;
    for (int i=1;i<=n;i++)   {
        cin>>dias[i];
        dias[i]+=dias[i-1];
    }
    for (int i=0;i<n;i++)   {
        ret=BinSearch(i,n,m);
        if (ret>=m) {
            if (ret==mi)    vec.push_back(i);
            else if (ret<mi)   {
                vec.clear();
                mi=ret;
                vec.push_back(i);
            }
        }
        else    break;
    }
    for (unsigned i=0;i<vec.size();i++)
        cout<<vec[i]+1<<'-'<<des[vec[i]]<<endl;
    return 0;
}

int BinSearch(int i,int n,int m)    {
    int mid,left=i+1,right=n;
    while (left<right)  {
        mid=(left+right)/2;
        if (dias[mid]-dias[i]>=m)    {
            right=mid;
        }
        else    {
            left=mid+1;
        }
    }
    des[i]=right;
    return dias[right]-dias[i];
}






















//#include <bits/stdc++.h>
//using namespace std;
//vector<int> nums,sum;
//map<int,vector<pair<int,int> >,less<int> > mp;
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int n,m,t;
//    bool flag=false;
//    cin>>n>>m;
//    for (int i=0;i<n;i++)   {
//        cin>>t;
//        nums.push_back(t);
//        sum.push_back(0);
//    }
//    for (int i=0;i<=n;i++)   {
//        if (i==0) sum[i]=0;
//        else    sum[i]=sum[i-1]+nums[i-1];
//    }
//    //for (int i=0;i<=n;i++)   cout<<sum[i]<<' ';
//    for (int i=0;i<=n;i++)   {
//        for (int j=0;j<i;j++)   {
//            if (sum[i]-sum[j]==m)   {
//                cout<<j+1<<'-'<<i<<endl;
//                flag=true;
//                continue;
//            }
//            else if (flag==false&&sum[i]-sum[j]>m)   {
//                int suffix=sum[i]-sum[j]-m;
//                mp[suffix].push_back(make_pair(j+1,i));
//                continue;
//            }
//        }
//    }
//    if (flag==false)    {
//        vector<pair<int,int> > nv=(*(mp.begin())).second;
//        for (unsigned i=0;i<nv.size();i++)
//            cout<<nv[i].first<<'-'<<nv[i].second<<endl;
//    }
//    return 0;
//}
