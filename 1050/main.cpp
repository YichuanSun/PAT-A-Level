#include <bits/stdc++.h>
using namespace std;
bool spot[400];
int main()  {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for (unsigned i=0;i<s2.size();i++)  {
        spot[s2[i]]=true;
    }
    for (int i=0;i<s1.size();i++)   {
        if (!spot[s1[i]])   cout<<s1[i];
    }
    cout<<endl;
    return 0;
}


/*
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for (unsigned i=0;i<s2.size();i++)   {
        for (unsigned j=0;j<s1.size();j++)   {
            if (s1[j]==s2[i])   s1[j]=1;
        }
    }
    for (unsigned i=0;i<s1.size();i++)   {
        if (s1[i]!=1)   cout<<s1[i];
    }
    cout<<endl;
    return 0;
}
*/
