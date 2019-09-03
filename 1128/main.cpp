#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N];
int main()  {
    int n,k;
    cin>>n;
    for (int i=0;i<n;i++)   {
        fill(a,a+N,0);
        cin>>k;
        for (int j=1;j<=k;j++)  cin>>a[j];
        int sp=0;
        for (int j=1;j<=k;j++)  {
            for (int m=j+1;m<=k;m++)    {
                if (a[j]==a[m]) sp=1;
                else if (j-a[j]==m-a[m]) sp=1;
                else if (j+a[j]==m+a[m]) sp=1;
                if (sp==1)  break;
            }
            if (sp==1)  break;
        }
        if (sp==1)  cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
