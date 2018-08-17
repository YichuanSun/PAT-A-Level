#include <bits/stdc++.h>
using namespace std;
vector<int> v,sum;
int main()  {
    int n,temp,s=0,tesum=0,first=0,last=0,cnt=0;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>temp;
        if (temp<0) cnt++;
        v.push_back(temp);
        sum.push_back(s+=temp);
    }
    if (cnt==n) {
        cout<<0<<' '<<v[0]<<' '<<v[n-1]<<endl;
        return 0;
    }
    tesum=sum[0];
    for (int i=0;i<n;i++)   {
        for (int j=0;j<i;j++)   {
            if (tesum<sum[i]-sum[j])    {
                tesum=sum[i]-sum[j];
                first=j+1,last=i;
            }
        }
    }
    cout<<tesum<<' '<<v[first]<<' '<<v[last]<<endl;
    return 0;
}
