#include <bits/stdc++.h>
using namespace std;
stack<int> st;
map<int,bool,less<int> > mid;
void spush();
void spop();
void spee();
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    char *a=new char[15];
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>a;
        if (a[1]=='u')  spush();
        else if (a[1]=='o') spop();
        else if (a[1]=='e') spee();
    }
    return 0;
}

void spush()    {
    int t;
    cin>>t;
    mid[t]=true;
    st.push(t);
}

void spop() {
    if (st.empty()) cout<<"Invalid"<<endl;
    else    {
        cout<<st.top()<<endl;
        mid.erase(st.top());
        st.pop();
    }
}

void spee() {
    if (st.empty()) {
        cout<<"Invalid"<<endl;
        return;
    }
    std::map<int,bool,less<int> >::iterator i1=mid.begin();
    int tt=(st.size()-1)/2;
    for (int i=0;i<tt;i++)  i1++;
    cout<<(*(i1)).first<<endl;
}



