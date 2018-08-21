#include <bits/stdc++.h>
#define N 60
using namespace std;
vector<int> des;
string tc[N],cards[N]={
 "","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
    "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
    "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
    "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2"};
int main()  {
    int n,t;
    cin>>n;
    des.push_back(0);
    for (int i=0;i<54;i++)   {
        cin>>t;
        des.push_back(t);
    }
    for (int i=0;i<N;i++)   tc[i]=cards[i];
    for (int i=0;i<n;i++)   {
        for (unsigned j=1;j<des.size();j++) {
            cards[des[j]]=tc[j];
        }
        for (int i=0;i<N;i++)   tc[i]=cards[i];
    }
    cout<<tc[1];
    for (unsigned i=2;i<=54;i++)    cout<<' '<<tc[i];
    cout<<endl;
    return 0;
}
