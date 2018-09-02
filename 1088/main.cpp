#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct number{
    int nu,de;
};
number a,b;
void add(number a,number b);
void dif(number a,number b);
void pro(number a,number b);
void quo(number a,number b);
ll gcd(ll x,ll y)    {
    if (x%y==0) return y;
    return gcd(y,x%y);
}
void pn(number c)   {
    bool flag=false;
    if (c.nu<0) {
        cout<<"(-";
        c.nu=-1*c.nu;
        flag=true;
    }
    if (c.nu/c.de!=0)   {
        cout<<c.nu/c.de;
        c.nu=c.nu%c.de;
    }
    else    {
        cout<<c.nu<<'/'<<c.de;
        if (flag)   cout<<')';
        return;
    }
    if (c.nu==0)    {
        if (flag)    cout<<')';
        return;
    }
    else    {
        cout<<' ';
        cout<<c.nu<<'/'<<c.de;
        return;
    }
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char ch;
    cin>>a.nu>>ch>>a.de>>b.nu>>ch>>b.de;
    add(a,b);
    dif(a,b);
    pro(a,b);
    quo(a,b);
    return 0;
}

void add(number a,number b) {
    pn(a);
    cout<<" + ";
    pn(b);
    cout<<" = ";
    ll ta=a.de*b.de/gcd(a.de,b.de);
    ll anu=a.nu*ta/a.de;
    ll bnu=b.nu*ta/b.de;
    ll tb=anu+bnu;
    if (tb==0)  {
        cout<<0<<endl;
        return;
    }
    while (gcd(tb,ta)!=1)   {
        ll gys=gcd(tb,ta);
        tb/=gys;
        ta/=gys;
    }
    number c;
    c.nu=tb;
    c.de=ta;
    pn(c);
}

void dif(number a,number b) {

}

void pro(number a,number b) {

}

void quo(number a,number b) {

}
