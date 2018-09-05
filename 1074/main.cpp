#include <bits/stdc++.h>
using namespace std;
struct node{
    int now,data,nex;
}nodes[100005],pp[100005];
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int f,n,k;
    node nnd;
    cin>>f>>n>>k;
    int ff=f;
    for (int i=0;i<n;i++)   {
        cin>>nnd.now>>nnd.data>>nnd.nex;
        nodes[nnd.now]=nnd;
    }
    int nn;
    for (nn=0;nn<n;nn++)   {
        pp[nn]=nodes[ff];
        ff=nodes[ff].nex;
        if (ff==-1) break;
    }
    nn++;
    for (int i=0;i<nn;i+=k)   {
        if (i+k>nn) break;
        reverse(pp+i,pp+i+k);
    }
    for (int i=0;i<nn-1;i++){
        cout.fill('0');
        cout.width(5);
        cout<<pp[i].now<<' ';
        cout<<pp[i].data<<' ';
        if (pp[i].nex!=-1)  {
            cout.fill('0');
            cout.width(5);
        }
        cout<<pp[i+1].now<<endl;
    }
    cout.fill('0');
    cout.width(5);
    cout<<pp[nn-1].now;
    cout<<' '<<pp[nn-1].data<<' '<<-1<<endl;
    return 0;
}
