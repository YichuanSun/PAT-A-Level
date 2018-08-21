#include <bits/stdc++.h>
using namespace std;

string subf(string x)   {
    int i=0;
    while (x[i]=='0')   i++;
    return x.substr(i);
}
bool cmp(string a,string b)  {
    string af=a+b,bf=b+a;
    af=subf(a+b);
    bf=subf(b+a);
    if (af.size()<bf.size())    return 1;
    else if (af.size()==bf.size())   return af<bf;
    else    return 0;
}
vector<string> vs;
int main()  {
    int n;
    cin>>n;
    string temp;
    for (int i=0;i<n;i++)   {
        cin>>temp;
        vs.push_back(temp);
    }
    sort(vs.begin(),vs.end(),cmp);
    if (!vs.empty())    {
        vs[0]=subf(vs[0]);
        cout<<vs[0];
        for (int i=1;i<n;i++)   {
            if (vs[i-1]=="")    vs[i]=subf(vs[0]);
            if (i==n-1&&vs[i]=="")  vs[i]="0";
            cout<<vs[i];
        }
        cout<<endl;
    }
    return 0;
}
