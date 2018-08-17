#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n1,n2,n=s.length();
    n1=s.length()/3;
    n2=s.length()/3+s.length()%3;
    if (n%3==0)
    {
        for (int i=0; i<n1-1; i++)
        {
            cout<<s[i];
            for (int j=1; j<=n2; j++)
                cout<<' ';
            cout<<s[n-i-1]<<endl;
        }
        for (int i=n1-1; i<=n1+n2; i++)
            cout<<s[i];
        cout<<endl;
    }
    else
    {
        n1--;
        for (int i=0; i<=n1; i++)
        {
            cout<<s[i];
            for (int j=1; j<=n2-2; j++)
                cout<<' ';
            cout<<s[n-i-1]<<endl;
        }
        for (int i=n1+1; i<=n1+n2; i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}
