//用了set，自动排序，比vector一次一排强多了
//没有切割字符串，而是循环控制的
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
map<string, set<int>> mpTitle, mpAuthor, mpKey, mpPub,mpYear;
void query(map<string, set<int>>& mp, string& str) {
    if(mp.find(str) == mp.end()) {
        printf("Not Found\n");
    } else {
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
            printf("%07d\n", *it);
        }
    }
}
int main() {
    int n, m, id, type;
    string title, author, key, pub, year;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        char c = getchar();
        getline(cin, title);
        mpTitle[title].insert(id);
        getline(cin, author);
        mpAuthor[author].insert(id);
        while(cin >> key) {
            mpKey[key].insert(id);
            c = getchar();
            if(c == '\n') {
                break;
            }
        }
        getline(cin, pub);
        mpPub[pub].insert(id);
        getline(cin, year);
        mpYear[year].insert(id);
        }
        string temp;
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d: ", &type);
            getline(cin, temp);
            cout<<type<<": "<<temp<<endl;
            if(type == 1) {
                query(mpTitle, temp);
            } else if(type == 2) {
                query(mpAuthor, temp);
            } else if(type == 3) {
                query(mpKey, temp);
            } else if(type == 4) {
                query(mpPub, temp);
            } else {
                query(mpYear, temp);
            }
        }
    return 0;
}























//#include <bits/stdc++.h>
//using namespace std;
//map<string,vector<int> > title,author,keyword,publisher,year;
//void printVector(vector<int> v);
//void printVector(map<string,vector<int> > a, string s);
//void splitString(string& a,vector<string>& b,string c);
//int main()  {
//    int n,ID,select;
//    string t,a,k,p,y,st;
//    scanf("%d",&n);
//    while (n--) {
//        vector<string> b;
//        scanf("%d",&ID);
//        getchar();
//        getline(cin,t);
//        getline(cin,a);
//        getline(cin,k);
//        getline(cin,p);
//        getline(cin,y);
//        title[t].push_back(ID);
//        sort(title[t].begin(),title[t].end());
//        author[a].push_back(ID);
//        sort(author[a].begin(),author[a].end());
//        splitString(k,b," ");
//        for (int i=0;i<b.size();i++)    {
//            keyword[b[i]].push_back(ID);
//            sort(keyword[b[i]].begin(),keyword[b[i]].end());
//        }
//        publisher[p].push_back(ID);
//        sort(publisher[p].begin(),publisher[p].end());
//        year[y].push_back(ID);
//        sort(year[y].begin(),year[y].end());
//    }
//    scanf("%d",&n);
//    while (n--) {
//        scanf("%d: ",&select);
//        cout<<select<<": ";
//        getline(cin,st);
//        cout<<st<<endl;
//        switch(select)  {
//            case 1: printVector(title,st);break;
//            case 2: printVector(author,st);break;
//            case 3: printVector(keyword,st);break;
//            case 4: printVector(publisher,st);break;
//            case 5: printVector(year,st);break;
//        }
//    }
//    return 0;
//}
//
//void printVector(map<string,vector<int> > a, string s) {
//    if (a.find(s)==a.end()) {
//        printf("Not Found\n");
//        return;
//    }
//    for (int i=0;i<a[s].size();i++) printf("%d\n",a[s][i]);
//}
//
//void splitString(string& a,vector<string>& b,string c)  {
//    int pos1,pos2;
//    pos1=0;
//    pos2=a.find(c);
//    while (string::npos!=pos2)  {
//        b.push_back(a.substr(pos1,pos2-pos1));
//        pos1=pos2+c.size();
//        pos2=a.find(c,pos1);
//    }
//    if (pos1!=a.length())   b.push_back(a.substr(pos1));
//}
//
