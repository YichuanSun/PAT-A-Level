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
    string nt=y;
    if (nt[0]=='0'&&nt.size()==1)   {
        cout<<'0';
        return;
    }
    for (unsigned i=0;i<nt.size();i++)  {
        if (nt[i]!=0)   break;
        if (i+1<nt.size()&&nt[i+1]!='.')  nt.erase(i,1);
    }
    if (nt[0]=='0') nt.erase(0,1);
    int des=nt.find('.');
    if (des!=-1)    nt.erase(des,1);
    string ts=nt.substr(0,n);
    unsigned i=0;
    for (;y[i]!='.'&&i<y.size();i++);
    if (y[0]=='0')  i--;
    cout<<"0."<<ts;
    for (unsigned j=ts.size();j<n;j++)  cout<<'0';
    if (i!=0)    cout<<"*10^"<<i;
}
