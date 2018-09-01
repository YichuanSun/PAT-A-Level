#include <bits/stdc++.h>
using namespace std;
map<char,bool> spot;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b,c="";
    cin>>a>>b;
    unsigned i=0,j=0;
    while (i<a.size()&&j<b.size())   {
        if (a[i]==b[j]) {
            i++,j++;
        }
        else    {
            char tc=a[i];
            if (a[i]>='a'&&a[i]<='z')
                tc=a[i]-'a'+'A';
            if (spot[tc]||spot[a[i]])   {
                i++;
                continue;
            }
            spot[a[i]]=spot[tc]=true;
            c+=tc;
            i++;
        }
    }
    cout<<c<<endl;
    return 0;
}
