#include <bits/stdc++.h>
using namespace std;
char a[10005];
char itg[10005];
char dcm[10005];
char ept[10005];
bool isr;
int exs(char *s);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    if (a[0]=='-')  cout<<'-';
    int i=1,cnt1=0,cnt2=0,cnt3=0;
    while (a[i]=='0')   i++;
    while (a[i]!='.')   itg[cnt1++]=a[i++];
    int dd=i++;
    while (a[i]!='E')   dcm[cnt2++]=a[i++];
    i++;
    if (a[i++]=='+')  isr=true;
    while (a[i]=='0')   i++;
    while (a[i]!='\0')  ept[cnt3++]=a[i++];
    int e=exs(ept);
    if (isr)    {
        if (e>=cnt2)    {
            for (int j=0;j<cnt1;j++)    cout<<itg[j];
            for (int j=0;j<cnt2;j++)    cout<<dcm[j];
            for (int j=0;j<e-cnt2;j++)  cout<<0;
            cout<<endl;
        }
        else{
            for (int j=0;j<cnt1;j++)    cout<<itg[j];
            for (int j=0;j<e;j++)   cout<<dcm[j];
            cout<<'.';
            for (int j=e;j<cnt2;j++)    cout<<dcm[j];
            cout<<endl;
        }
    }
    else    {
        if (e>=cnt1)    {
            cout<<"0.";
            for (int j=0;j<e-cnt1;j++)  cout<<0;
            for (int j=0;j<cnt1;j++)    cout<<itg[j];
            for (int j=0;j<cnt2;j++)    cout<<dcm[j];
            cout<<endl;
        }
        else    {
            for (int j=0;j<cnt1-e;j++)   cout<<itg[j];
            cout<<'.';
            for (int j=cnt1-e;j<cnt1;j++)   cout<<itg[j];
            for (int j=0;j<cnt2;j++)    cout<<dcm[j];
            cout<<endl;
        }
    }
    return 0;
}

int exs(char *s)    {
    int n=0,p=1;
    for (int i=strlen(s)-1;i>=0;i--)    {
        n+=(s[i]-'0')*p;
        p*=10;
    }
    return n;
}
