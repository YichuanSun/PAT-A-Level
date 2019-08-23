#include <bits/stdc++.h>
#define N 1005
using namespace std;
string add(string s1, string s2)
{
    string s = s1;
    int carry = 0;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }
    if (carry > 0)
        s = "1" + s;
    return s;
}
int main()
{
    string s,t;
    int cnt=0;
    cin>>s;
    t=s;
    reverse(t.begin(),t.end());
    while (t!=s&&cnt<10)
    {
        cout<<s<<" + "<<t<<" = ";
        string sm=add(s,t);
        cout<<sm<<endl;
        s=t=sm;
        reverse(t.begin(),t.end());
        cnt++;
    }
    if (t==s)
        cout<<t<<" is a palindromic number.\n";
    else
        cout<<"Not found in 10 iterations.\n";
    return 0;
}




