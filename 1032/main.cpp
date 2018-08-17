#include <bits/stdc++.h>
#define INF 0x7FFFFFFF
using namespace std;
struct st{
    int pre,nex;
    char c;
};
vector<st> sts;
bool jud(st a)  {
    if (a.nex==-1)  return true;
    else return false;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<INF<<endl;
    st nst;
    int des1,des2,n;
    cin>>des1>>des2>>n;
    for (int i=0;i<n;i++)   {
        cin>>nst.pre>>nst.c>>nst.nex;
        sts.push_back(nst);
    }
    std::vector<st>::iterator ite=find_if(sts.end(),sts.begin(),jud);
    cout<<(*ite).pre<<endl;
    return 0;
}
