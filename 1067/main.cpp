#include <bits/stdc++.h>
#define N 100005
using namespace std;

int des[N];
int isOK(int be,int en) {
    for (int i=be;i<en;i++)
        if (des[i]!=i)  return i;
    return 0;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,cnt=0;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>t;
        des[t]=i;
    }
    int first=isOK(1,n);
    while (first)   {
        if (des[0]==0)  {
            des[0]=des[first];
            des[first]=0;
            cnt++;
        }
        while (des[0]!=0)    {
            t=des[0];
            des[0]=des[t];
            des[t]=t;
            cnt++;
        }
        first=isOK(first,n);
    }
    cout<<cnt<<endl;
    return 0;
}
