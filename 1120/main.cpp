#include <bits/stdc++.h>
#define N 10005
using namespace std;
int a[N];
set<int> s;
int cal(int t)  {
    int sum=0;
    while (t)   {
        sum+=t%10;
        t/=10;
    }
    return sum;
}
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>a[i];
        a[i]=cal(a[i]);
        s.insert(a[i]);
    }
    set<int>::iterator it0=s.begin();
    cout<<s.size()<<endl;
    cout<<*(it0++);
    for (;it0!=s.end();it0++)
        cout<<' '<<(*it0);
    cout<<endl;
    return 0;
}
