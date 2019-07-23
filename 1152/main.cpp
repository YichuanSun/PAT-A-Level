#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n==0||n==1) return false;
    for (int i=2;i*i<=n;i++)    {
        if (n%i==0) return false;
    }
    return true;
}

int main()  {
    int l,m;
    string s;
    cin>>l>>m;
    cin>>s;
    for (int i=0;i<=l-m;i++) {
        string ts=s.substr(i,m);
        int t=stoi(ts);
        if (isPrime(t)) {
            cout<<ts<<endl;
            return 0;
        }
    }
    cout<<404<<endl;
    return 0;
}

