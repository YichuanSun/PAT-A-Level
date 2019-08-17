//#include <bits/stdc++.h>
//using namespace std;
//string op(string ts);
//int main()  {
//    int n;
//    string s;
//    cin>>s>>n;
//    for (int i=0;i<n-1;i++)   s=op(s);
//    cout<<s<<endl;
//    return 0;
//}
//
//string op(string ts)    {
//    string res="";
//    if (ts.size()==1)   {res+=ts;res+="1";return res;}
//    char c=ts[0];
//    int cnt=1;
//    for (int i=1;i<(int)ts.size();i++)  {
//        if (ts[i]==c)   cnt++;
//        else {
//            res+=c;
//            res+=to_string(cnt);
//            cnt=1;
//            c=ts[i];
//        }
//    }
//    res+=c;
//    res+=to_string(cnt);
//    return res;
//}

#include <bits/stdc++.h>
using namespace std;
string char_count(string str){
    string res="";
    if (str.size()==1)   {res+=str;res+="1";return res;}
    int cnt = 1;
    char c=str[0];
    for(int i=1; i<(int)str.length(); i++){
        if(c == str[i]){cnt++;}
        else{
            res +=c;
            res +=to_string(cnt);
            cnt = 1;
            c = str[i];
        }
    }
    res +=c;        //把所有的res=res+c这种全部变成了自增，就不超时了
    res +=to_string(cnt);
    return res;
}

int main()  {
    int n;
    string res;
    cin>>res>>n;
    for (int i=0;i<n-1;i++)
        res = char_count(res);
    cout << res << endl;
    return 0;
}

////by liuchuo
//#include <iostream>
//using namespace std;
//int main()
//{
//    string s;
//    int n, j;
//    cin >> s >> n;
//    for (int cnt = 1; cnt < n; cnt++)
//    {
//        string t;
//        for (int i = 0; i < s.length(); i = j)
//        {
//            for (j = i; j < s.length() && s[j] == s[i]; j++);
//            t += s[i] + to_string(j - i);
//        }
//        s = t;
//    }
//    cout << s;
//    return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()  {
//    string d;
//    int n;
//    cin>>d>>n;
//    for (int i=0;i<n;i++)   {
//        string t="";
//        int k=1,sz=(int)d.size();
//        cout<<d<<endl;
//        if (sz==1)  {
//            t+=d;
//            t+=('0'+1);
//            d=t;
//            continue;
//        }
//        while (k<sz) {
//            if (k==sz-1&&d[k-1]!=d[k])  {
//                t=d;
//                t+=d[k-1];
//                t+='0'+1;
//                k++;
//                continue;
//            }
//            int ori=k;
//            //cout<<"now k = "<<ori<<endl;
//            int cnt=1;
//            while (k<sz&&d[k]==d[k-1])    {
//                cnt++;
//                k++;
//            }
//            t+=d[k-1];
//            string nw="";
//            while (cnt!=0)  {
//                nw+='0'+cnt%10;
//                cnt/=10;
//            }
//            reverse(nw.begin(),nw.end());
//            t+=nw;
//            if (k==ori) k++;
//        }
//        d=t;
//    }
//    cout<<d<<endl;
//    return 0;
//}
