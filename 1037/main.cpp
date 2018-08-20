#include <bits/stdc++.h>
using namespace std;
vector<double> coupon,product;
queue<double> pc,nc,pp,np;
bool cmp(double a,double b) {
    return a>b;
}
int main()  {
    int nc,np;
    double temp,ans=0;
    cin>>nc;
    for (int i=0;i<nc;i++)  {
        cin>>temp;
        coupon.push_back(temp);
    }
    cin>>np;
    for (int i=0;i<np;i++)  {
        cin>>temp;
        product.push_back(temp);
    }
    sort(coupon.begin(),coupon.end(),cmp);
    sort(product.begin(),product.end(),cmp);
    int spot1,spot2;
    for (spot1=0;coupon[spot1]>0&&spot1<coupon.size();spot1++);
    for (spot2=0;product[spot2]>0&&spot2<product.size();spot2++);
    int cnt=0;
    double value;
    for (int i=0;i<coupon.size();i++)   {
        if (cnt>=product.size())    break;
        value=coupon[i]*product[cnt];
        if (value>=0)   {
            ans+=value;
            cnt++;
        }
        if (i>=spot1||cnt>=spot2) break;
    }
    cnt=product.size()-1;
    for (int i=coupon.size()-1;i>=spot1;i--)    {
        if (cnt<spot2)  break;
        value=coupon[i]*product[cnt];
        if (value>=0)   {
            ans+=value;
            cnt--;
        }
        if (i<spot1||cnt<spot2) break;
    }
    cout<<ans<<endl;
    return 0;
}
