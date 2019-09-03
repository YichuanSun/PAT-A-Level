#include <bits/stdc++.h>
#define N 50005
using namespace std;
int a[N],frq[N];
struct cmp{
    bool operator ()(int a,int b) {
        if (frq[a]==frq[b])  return a<b;
        else return     frq[a]>frq[b];
    }
};
set<int,cmp>    sic;
int main()  {
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)   cin>>a[i];
    for (int i=1;i<n;i++)   {
        if (i==0)   continue;
        set<int,cmp>::iterator it1=sic.find(a[i-1]);
        if (it1!=sic.end())  {sic.erase(it1);}
        frq[a[i-1]]++;
        sic.insert(a[i-1]);
        cout<<a[i]<<':';
        set<int,cmp>::iterator it0=sic.begin();
        int j=0;
        for (;it0!=sic.end()&&j<k;j++,it0++)    cout<<' '<<(*it0);
        cout<<endl;
    }
    return 0;
}


//#include <bits/stdc++.h>
//#define N 50005
//using namespace std;
//int a[N],frq[N],usd[N];
//vector<int> vr;
//bool cmp(int a,int b)   {
//    if (frq[a]==frq[b]) return a<b;
//    return frq[a]>frq[b];
//}
//int main()  {
//    int n,k,sml=-1;
//    cin>>n>>k;
//    for (int i=0;i<n;i++)   {
//        cin>>a[i];
//        if (i==0)   {continue;}
//        frq[a[i-1]]++;
//        if ((int)vr.size()<k)    {   //如果序列未满
//            if (usd[a[i-1]]==0)   {   //如果序列中无该值
//                vr.push_back(a[i-1]);
//                usd[a[i-1]]=1;
//            }
//            else {
//                sort(vr.begin(),vr.end(),cmp);
//                if (!vr.empty())    sml=frq[vr.back()];
//            }
//
//        }
//        else {  //序列已满
//            if (usd[a[i-1]]==0)   {   //如果序列中无该值
//                if (frq[a[i-1]]>=sml)  {   //并且这个值出现频数大于等于序列中的最小值
//                    vr.push_back(a[i-1]);
//                    sort(vr.begin(),vr.end(),cmp);
//                    if (vr.back()!=a[i-1])    {usd[a[i-1]]=1;usd[vr.back()]=0;}
//                    vr.pop_back();
//                    if (!vr.empty())    sml=frq[vr.back()];
//                }
//            }
//            else {  //如果有该值
//                sort(vr.begin(),vr.end(),cmp);
//                if (!vr.empty()) sml=frq[vr.back()];
//            }
//        }
//        cout<<a[i]<<':';
//        for (int j=0;j<(int)vr.size();j++)
//            cout<<' '<<vr[j];
//        cout<<endl;
//    }
//    return 0;
//}
