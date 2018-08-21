#include <bits/stdc++.h>
using namespace std;
map<int,int> num;
vector<int> save;
int main()  {
    int n,t;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>t;
        num[t]+=1;
        save.push_back(t);
    }
    for (int i=0;i<n;i++)   {
        if (num[save[i]]==1)    {
            cout<<save[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}
