#include <bits/stdc++.h>
using namespace std;

int main()  {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,len=0;
    scanf("%d",&n);
    getchar();
    string a,b,c,e;
    getline(cin,a);
    getline(cin,b);
    int ta=a.size()-1,tb=b.size()-1;
    while (ta>=0&&tb>=0&&a[ta]==b[tb])  {
        ta--,tb--;
    }
    if (ta!=a.size()-1) len=a.size()-1-ta;
    else    {
        for (int i=2;i<n;i++)   getline(cin,e);
        cout<<"nai"<<endl;
        return 0;
    }
    string d=a.substr(ta+1);
    bool flag=true;
    for (int i=2;i<n;i++)   {
        getline(cin,e);
        if (e.size()<len)   flag=false;
        else    {
            string te=e.substr(e.size()-len);
            if (te!=d)  flag=false;
        }
    }
    if (flag)   cout<<d<<endl;
    else    cout<<"nai"<<endl;
    return 0;
}



