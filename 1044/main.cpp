#include <bits/stdc++.h>
using namespace std;
vector<int> nums,sum;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,t,mmax=0;
    cin>>n>>m;
    for (int i=0;i<n;i++)   {
        cin>>t;
        nums.push_back(t);
        sum.push_back(0);
    }
    for (int i=0;i<n;i++)   {
        if (i==0) sum[i]=0;
        else    sum[i]=sum[i-1]+nums[i-1];
    }
    //for (int i=0;i<n;i++)   cout<<sum[i]<<' ';
    for (int i=0;i<n;i++)   {
        for (int j=0;j<i;j++)   {
            if (sum[i]-sum[j]==m)   {
                cout<<j+1<<'-'<<i<<endl;
                continue;
            }
            else if (sum[i]-sum[j]>m)   {
                mmax=max(sum[i]-sum[j],mmax);
            }
        }
    }
    return 0;
}
