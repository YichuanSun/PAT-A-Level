#include <bits/stdc++.h>
#define N 1005
using namespace std;

typedef pair<string,int> psi;
struct cmp1 {
    bool operator ()(psi &a,psi &b) {
        if (a.second==b.second) return a.first>b.first;
        else return a.second<b.second;
    }
};

typedef priority_queue<psi,vector<psi>,cmp1> ppx;   //我真不知道怎么命名了，怎么写才又短又好听？
ppx pt,pa,pb;
vector<psi> vp;
int site_num[N],site_sc[N];
int cnt;

void ope(int n);
void oup(ppx tppx);
int main()  {
    int n,m,sc;
    string sda;
    cin>>n>>m;
    for (int i=0;i<n;i++)   {
        cin>>sda;
        cin>>sc;
        psi tpsi=make_pair(sda,sc);
        switch(sda[0])  {
            case 'T': pt.push(tpsi);break;
            case 'A': pa.push(tpsi);break;
            case 'B': pb.push(tpsi);break;
        }
        vp.push_back(tpsi);
        int sit=stoi(sda.substr(1,3));
        site_num[sit]++;
        site_sc[sit]+=sc;
    }
    for (int i=0;i<m;i++)   {
        int op;
        cin>>op;
        ope(op);
    }
    return 0;
}

void ope(int n) {
    cnt++;
    char ch;
    int ti;
    if (n==1)   {
        cin>>ch;
        cout<<"Case "<<cnt<<": "<<n<<' '<<ch<<endl;
        switch(ch)  {
            case 'T': oup(pt);break;
            case 'A': oup(pa);break;
            case 'B': oup(pb);break;
            default: break;
        }
    }
    else {
        cin>>ti;
        cout<<"Case "<<cnt<<": "<<n<<' '<<ti<<endl;
        if (n==2)  {
            if (site_num[ti]||site_sc[ti])
                cout<<site_num[ti]<<' '<<site_sc[ti]<<endl;
            else cout<<"NA"<<endl;
        }
    }
}

void oup(ppx tppx)  {
    if (tppx.empty())   cout<<"NA"<<endl;
    while (!tppx.empty())   {
        psi tps=tppx.top();
        tppx.pop();
        cout<<tps.first<<' '<<tps.second<<endl;
    }
}
