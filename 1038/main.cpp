#include <bits/stdc++.h>
using namespace std;
vector<string> li;
bool cmp(string a,string b) {
    if (a.size()==b.size()) {
        return a<b;
    }
    else if (a.size()<b.size()) {
        int sub=b.size()-a.size();
        string ts=b.substr(sub);
        if (ts)
    }
    else    {

    }
}
int main()  {
    int n;
    string st;
    for (int i=0;i<n;i++)   {
        cin>>st;
        li.push_back(st);
    }

    return 0;
}
