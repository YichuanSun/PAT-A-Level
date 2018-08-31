#include <bits/stdc++.h>
using namespace std;

vector<string> v={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
int main()  {
    int n;
    cin>>n;
    if (n<0)    {
        cout<<'Fu ';
        n=abs(n);
    }
    if (n>99999999) {
        cout<<v[n/100000000]<<' ';
        cout<<"Yi ";
    }
    n%=100000000;
    if (n>9999) {
        int m=n/10000;
        if (m<1000) {
            bool flag=false;
            cout<<v[0]<<' ';
            flag=true;
            int j=m/100;
            if (j!=0)   {
                cout<<v[j]<<" Bai ";
                j=m%100;
                if (j!=0)   cout<<v[j]<<"Shi ";
                else    {
                    if (!flag)    {
                        cout<<v[0]<<' ';
                        flag=true;
                    }
                    j=m%10;
                    if (j!=0)   cout<<v[j]<<' ';
                }
            }
            else    {
                cout<<v[0]<<' ';
                j=m/10;
                if (j!=0)   cout<<v[j]<<"Shi ";
                else    {
                    if (!flag)    {
                        cout<<v[0]<<' ';
                        flag=true;
                    }
                    j=m%10;
                    if (j!=0)   cout<<v[j]<<' ';
                }
            }
        }
        else    {
            cout<<v[m/1000]<<"Qian ";
            int j=m/100;
            if (j!=0)   cout<<v[j]<<"Bai ";
            else    {
                j=m/10;
                if (j!=0)   cout<<v[j]<<"Shi ";
                else    {
                    j=m%10;
                    if (j!=0)   cout<<v[j]<<' ';
                }
            }
        }
        cout<<"Wan ";
    }
    return 0;
}


