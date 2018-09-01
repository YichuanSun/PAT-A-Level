/*
字符串类的成员函数find：如果找不到，返回
一个该字符串对象的特定的值npos，如果用
a.find,则找不到就返回a.npos,找到就返回
第一个找到的元素的下标
*/
#include <bits/stdc++.h>
using namespace std;
map<char,bool> m;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b,c="";
    cin>>a>>b;
    for (unsigned i=0;i<a.size();i++)
        if (a[i]>='a'&&a[i]<='z')
            a[i]=a[i]-'a'+'A';
    for (unsigned i=0;i<b.size();i++)
        if (b[i]>='a'&&b[i]<='z')
            b[i]=b[i]-'a'+'A';
    for (unsigned i=0;i<a.size();i++)   {
        if (m[a[i]]==true)  continue;
        if (b.find(a[i])==b.npos) {
            m[a[i]]=true;
            c+=a[i];
        }
    }
    cout<<c<<endl;
    return 0;
}






















//#include <bits/stdc++.h>
//using namespace std;
//map<char,bool> spot;
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    string a,b,c="";
//    cin>>a>>b;
//    unsigned i=0,j=0;
//    while (i<a.size()&&j<b.size())   {
//        if (a[i]==b[j]) {
//            i++,j++;
//        }
//        else    {
//            char tc=a[i];
//            if (a[i]>='a'&&a[i]<='z')
//                tc=a[i]-'a'+'A';
//            if (spot[tc]||spot[a[i]])   {
//                i++;
//                continue;
//            }
//            spot[a[i]]=spot[tc]=true;
//            c+=tc;
//            i++;
//        }
//    }
//    cout<<c<<endl;
//    return 0;
//}
