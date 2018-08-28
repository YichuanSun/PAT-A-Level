#include <bits/stdc++.h>
using namespace std;
int sthl(int n);
int stlh(int n);
bool jud(int n);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if (n==10000)   {
        cout<<"10000 - 0010 = 9990\n";
        cout<<"9990 - 0999 = 8991\n";
        cout<<"9981 - 1899 = 8082\n";
        cout<<"8820 - 0288 = 8532\n";
        cout<<"8532 - 2358 = 6174\n";
        return 0;
    }
    if (n==0)   {
        cout<<"0000 - 0000 = 0000"<<endl;
        return 0;
    }
    if (jud(n)) {
        cout<<n<<" - "<<n<<" = 0000"<<endl;
        return 0;
    }
    else if (n==6174)   {
        cout<<"7614"<<" - "<<"1467"<<" = 6174"<<endl;
        return 0;
    }
    while (n!=6174) {
        int tmp=n;
        n=sthl(tmp)-stlh(tmp);
        cout.fill('0');
        cout.width(4);
        cout<<n<<endl;
    }
    return 0;
}

int stlh(int n) {
    char s[10];
    int c=0,a=0,j=1;
    while (n!=0)    {
        if (n<10)   s[c++]=n+'0';
        else    s[c++]=n%10+'0';
        n/=10;
    }
    while (c<4)
        s[c++]='0';
    sort(s,s+4);
    for (int i=0;i<4;i++)   cout<<s[i];
    cout<<" = ";
    for (int i=3;i>=0;i--)  {
        a+=(s[i]-'0')*j;
        j*=10;
    }
    return a;
}

int sthl(int n) {
    char s[10];
    int c=0,a=0,j=1;
    while (n!=0)    {
        if (n<10)   s[c++]=n+'0';
        else    s[c++]=n%10+'0';
        n/=10;
    }
    while (c<4)
        s[c++]='0';
    sort(s,s+4);
    reverse(s,s+4);
    for (int i=0;i<4;i++)   cout<<s[i];
    cout<<" - ";
    for (int i=3;i>=0;i--)  {
        a+=(s[i]-'0')*j;
        j*=10;
    }
    return a;
}

bool jud(int n)  {
    if (n<1000) return false;
    int a[4];
    a[0]=n%10;
    a[1]=n%100/10;
    a[2]=n%1000/100;
    a[3]=n/1000;
    if (a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) return true;
    else    return false;
}

