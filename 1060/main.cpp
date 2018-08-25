#include <bits/stdc++.h>
using namespace std;
void prf(string y);
int n;
int main(){
    string a,b;
    cin>>n>>a>>b;
    if (n==0)   {
        cout<<"YES 0"<<endl;
        return 0;
    }
    if (a.substr(0,n)!=b.substr(0,n))   {
        cout<<"NO ";
        prf(a),cout<<' ',prf(b),cout<<endl;
    }
    else    {
        cout<<"YES ";
        prf(b);
        cout<<endl;
    }
    return 0;
}

void prf(string y){
    string ts=y.substr(0,n);
    if (ts[0]=='0'&&ts.size()==1)   {
        cout<<'0';
        return;
    }
    ts.erase(ts.find('.'));
    unsigned i=0;
    for (;y[i]!='.'&&i<y.size();i++);
    cout<<"0."<<ts<<"*10^"<<i;
}
