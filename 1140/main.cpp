//#include <bits/stdc++.h>
//using namespace std;
//string char_count(string str){
//    string res;
//    int cnt = 1;
//    char c=str[0];
//    for(int i=1; i<(int)str.length(); i++){
//        if(c == str[i]){cnt++;}
//        else{
//            res = res + c;
////            string ts="";
////            while (cnt>0)   {
////                ts+=char(cnt%10+'0');
////                cnt/=10;
////            }
////            reverse(ts.begin(),ts.end());
//            res = res + to_string(cnt);
//            cnt = 1;
//            c = str[i];
//        }
//    }
//    res = res + c;
//    res = res + char(cnt + '0');
//    return res;
//}
//
//int main()  {
//    int n;
//    string res;
//    //cin>>res>>n;
//    res="6";
//    n=40;
//    for (int i=0;i<n;i++)
//        res = (i==0?res:char_count(res));
//    cout << res << endl;
//    return 0;
//}

//Áø‹S×ö·¨
#include <iostream>
using namespace std;
int main()
{
    string s;
    int n, j;
    //cin >> s >> n;
    s="8";
    n=40;
    for (int cnt = 1; cnt < n; cnt++)
    {
        string t;
        for (int i = 0; i < s.length(); i = j)
        {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            t += s[i] + to_string(j - i);
        }
        s = t;
    }
    cout << s;
    return 0;
}

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
