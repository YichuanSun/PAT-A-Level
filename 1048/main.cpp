#include <bits/stdc++.h>
#define N 100005
using namespace std;
int d[N];
int main()  {
    int n,m,mid;
    int dif;
    cin>>n>>m;
    for (int i=0;i<n;i++)   cin>>d[i];
    sort(d,d+n);
    for (int i=0;i<n;i++)   {
        dif=m-d[i];
        int left=i+1,right=n-1;
        while (left<=right)  {
            mid=(left+right)/2;
            if (d[mid]>dif) right=mid-1;
            else if (d[mid]<dif)    left=mid+1;
            else    break;
        }
        if (d[mid]==dif)    {
            cout<<d[i]<<' '<<d[mid]<<endl;
            return 0;
        }
    }
    cout<<"No Solution"<<endl;
    return 0;
}
