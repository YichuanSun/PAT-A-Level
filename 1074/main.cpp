#include <bits/stdc++.h>
using namespace std;
struct node{
    int now,data,nex;
}nodes[100005],pp[100005];
int main()  {
    int f,n,k;
    node nnd;
    cin>>f>>n>>k;
    int ff=f;
    for (int i=0;i<n;i++)   {
        cin>>nnd.now>>nnd.data>>nnd.nex;
        nodes[nnd.now]=nnd;
    }
    for (int i=0;i<n;i++)   {
        pp[i]=nodes[ff];
        ff=nodes[ff].nex;
    }
    for (int i=0;i<n;i+=k)   {
        if (i+k>n) break;
        reverse(pp+i,pp+i+k);
        int tadd=pp[i].nex;
        for (int j=i;j<i+k-1;j++) {
            pp[j].nex=pp[j+1].now;
        }
        if (i+k+k>n)    pp[i+k-1].nex=tadd;
        else    pp[i+k-1].nex=pp[i+k+k-1].now;
    }
    for (int i=0;i<n;i++){
        cout.fill('0');
        cout.width(5);
        cout<<pp[i].now<<' ';
        cout<<pp[i].data<<' ';
        if (pp[i].nex!=-1)  {
            cout.fill('0');
            cout.width(5);
        }
        cout<<pp[i].nex<<endl;
    }
    return 0;
}
