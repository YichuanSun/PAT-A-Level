#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,ans=0;
    long long p;
    cin>>n>>p;
    for (int i=0;i<n;i++)   {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for (int i=v.size()-1;i>=0;i--) {
        bool flag=false;
        for (int j=0;j<i;j++)   {
            if (flag)   break;
            if ((long long)v[i]<=p*v[j])   {
                ans=max(ans,i-j+1);
                flag=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}






















//#include <bits/stdc++.h>
//using namespace std;
//vector<int> a;
//vector<double> su[100005];
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int n,p,t;
//    cin>>n>>p;
//    for (int i=0;i<n;i++)   {
//        cin>>t;
//        a.push_back(t);
//    }
//    sort(a.begin(),a.end());
//    int ans=0;
//    for (int i=a.size()-1;i>=0;i--)    {
//        int tp=a[i]/p;
//        int l=0,r=i;
//        int mid;
//        while (l<r) {
//            mid=(l+r)/2;
//            if (tp>a[mid])  l=mid+1;
//            else if (tp<a[mid]) r=mid-1;
//            else    break;
//        }
//        ans=max(ans,(int)i-mid);
//    }
//    cout<<ans<<endl;
//    return 0;
//}
