#include <bits/stdc++.h>
using namespace std;
map<string,int> stm;
vector<pair<string,int> > v;
bool cmp(pair<string,int> a,pair<string,int> b)   {
    if (a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    getline(cin,a);
    for (int i=0;i<a.size();i++)
        if (a[i]>='A'&&a[i]<='Z')   a[i]=a[i]-'A'+'a';
    for (int i=0;i<a.size();i++)    {
        if (!isalnum(a[i]))   continue;
        string b;
        while (isalnum(a[i]))   {
            b+=a[i];
            i++;
        }
        if (b.size()>0) {
            stm[b]++;
        }
    }
    map<string,int>::iterator it1=stm.begin();
    while (it1!=stm.end())  {
        v.push_back(*(it1));
        it1++;
    }
    sort(v.begin(),v.end(),cmp);
    if (!v.empty())   cout<<(*(v.begin())).first<<' '<<(*(v.begin())).second<<endl;
    return 0;
}
