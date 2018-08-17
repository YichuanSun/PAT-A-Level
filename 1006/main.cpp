#include <bits/stdc++.h>
using namespace std;
struct info {
    string id;
    int i1,i2,i3;
    int o1,o2,o3;
};
vector<info> infos;
bool cmpfirst(info a,info b) {
    if (a.i1==b.i1) {
        if (a.i2==b.i2) {
            return a.i3<b.i3;
        }
        else    return a.i2<b.i2;
    }
    else    return a.i1<b.i1;
}

bool cmplast(info a,info b) {
    if (a.o1==b.o1) {
        if (a.o2==b.o2) {
            return a.o3>b.o3;
        }
        else    return a.o2>b.o2;
    }
    else    return a.o1>b.o1;
}
int main()  {
    //ios::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);
    int m,ch;
    scanf("%d",&m);
    getchar();
    while (m--) {
        info te;
        cin>>te.id;
        scanf(" %d%c%d%c%d %d%c%d%c%d",&te.i1,&ch,&te.i2,&ch,&te.i3,&te.o1,&ch,&te.o2,&ch,&te.o3);
        getchar();
        //cout<<"m="<<m<<endl;
        infos.push_back(te);
    }
    /*
    cin>>m;
    while (m--) {
        info te;
        cin>>te.id;
        cin>>te.i1;cin>>ch;cin>>te.i2;cin>>ch;cin>>te.i3;
        cin>>te.o1;cin>>ch;cin>>te.o2;cin>>ch;cin>>te.o3;
        infos.push_back(te);
        cout<<"m="<<m<<endl;
    }*/
    sort(infos.begin(),infos.end(),cmpfirst);
    cout<<infos[0].id<<' ';
    sort(infos.begin(),infos.end(),cmplast);
    cout<<infos[0].id<<endl;
    return 0;
}
