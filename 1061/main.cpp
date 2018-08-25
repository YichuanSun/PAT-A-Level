#include <bits/stdc++.h>
using namespace std;

int main()  {
    string week[8]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool flag=false;
    for (int i=0;i<a.size()&&i<b.size();i++)    {
        if (a[i]==b[i]&&flag==false) {
            if (a[i]>='A'&&a[i]<='G') {
                cout<<week[a[i]-'A']<<' ';
                flag=true;
                continue;
            }
        }
        if (a[i]==b[i]&&flag)   {
            if (a[i]>=0&&a[i]<=9)   {
                cout.fill('0');
                cout.width(2);
                cout<<a[i];
                cout<<':';
                break;
            }
            else if (a[i]>='A'&&a[i]<='N'){
                cout.fill('0');
                cout.width(2);
                cout<<a[i]-'A'+10;
                cout<<':';
                break;
            }
        }
    }
    for (int i=0;i<c.size()&&i<d.size();i++)    {
        if (c[i]==d[i]) {
            if ((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z')) {
                cout.fill('0');
                cout.width(2);
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
