#include <bits/stdc++.h>
using namespace std;
struct ch{
    string team;
    string pw;
};
vector<ch> chs,chs1;
bool charChange(ch st);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,cnt=0;
    ch nch;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>nch.team>>nch.pw;
        chs.push_back(nch);
    }
    for (int i=0;i<n;i++)   {
        ch tch=chs[i];
        int tem=charChange(tch);
        cnt+=tem;
    }
    if (cnt==0) {
        if (n==1)   cout<<"There is "<<n<<" account and no account is modified"<<endl;
        else cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    else    {
        cout<<chs1.size()<<endl;
        for (unsigned i=0;i<chs1.size();i++)
            cout<<chs1[i].team<<' '<<chs1[i].pw<<endl;
    }
    return 0;
}

bool charChange(ch tempch) {
    int ccnt=0;
    string st=tempch.pw;
    for (unsigned i=0;i<st.size();i++)   {
        if (st[i]=='1') st[i]='@',ccnt++;
        else if (st[i]=='0')    st[i]='%',ccnt++;
        else if (st[i]=='l')    st[i]='L',ccnt++;
        else if (st[i]=='O')    st[i]='o',ccnt++;
    }
    tempch.pw=st;
    if (ccnt)   chs1.push_back(tempch);
    return ccnt;
}



