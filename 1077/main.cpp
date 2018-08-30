#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n;
    string st1,st2;
    scanf("%d",&n);
    getchar();
    getline(cin,st1);
    int longest=st1.size();
    for (int i=1;i<n;i++)   {
        getline(cin,st2);
        int k=0,k1=st1.size()-1,k2=st2.size()-1;
        while (k1>=0&&k2>=0&&k<longest&&st1[k1--]==st2[k2--])  {
            k++;
        }
        longest=k;
        st1=st2;
    }
    if (longest==0) cout<<"nai"<<endl;
    else {
        string ans="";
        for (int i=st1.size()-longest;i<st1.size();i++)
            ans+=st1[i];
        cout<<ans<<endl;
    }
    return 0;
}


//未知bug，没找出来
/*
由于我先判定前两个的最大公共后缀，并把它当做唯一的了
所以接下来如果出现更短的后缀的话，我也不识别了
比如这个用例：

3
123456
489253948871456
96261356

先判定前两行，得到最长公共后缀是456，如果碰到
后缀不是456的，就nai，然而第三行的数据后缀56，
也是他们的公共后缀，只是变短了，就不识别了
所以出现了bug
*/
//#include <bits/stdc++.h>
//using namespace std;
//
//int main()  {
//    int n,len=0;
//    scanf("%d",&n);
//    getchar();
//    string a,b,c,e;
//    getline(cin,a);
//    getline(cin,b);
//    int ta=a.size()-1,tb=b.size()-1;
//    while (ta>=0&&tb>=0&&a[ta]==b[tb])  {
//        ta--,tb--;
//    }
//    if (ta!=a.size()-1) len=a.size()-1-ta;
//    else    {
//        for (int i=2;i<n;i++)   getline(cin,e);
//        cout<<"nai"<<endl;
//        return 0;
//    }
//    string d=a.substr(ta+1);
//    bool flag=true;
//    for (int i=2;i<n;i++)   {
//        getline(cin,e);
//        if (e.size()<len)   flag=false;
//        else    {
//            string te=e.substr(e.size()-len);
//            if (te!=d)  flag=false;
//        }
//    }
//    if (flag)   cout<<d<<endl;
//    else    cout<<"nai"<<endl;
//    return 0;
//}
