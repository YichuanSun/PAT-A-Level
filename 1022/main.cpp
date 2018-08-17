#include <bits/stdc++.h>
using namespace std;
map<string,vector<int> > title,author,keyword,publisher,year;
void printVector(vector<int> v);
void printVector(map<string,vector<int> > a, string s);
void splitString(string& a,vector<string>& b,string c);
int main()  {
    int n,ID,select;
    string t,a,k,p,y,st;
    scanf("%d",&n);
    while (n--) {
        vector<string> b;
        scanf("%d",&ID);
        getchar();
        getline(cin,t);
        getline(cin,a);
        getline(cin,k);
        getline(cin,p);
        getline(cin,y);
        title[t].push_back(ID);
        sort(title[t].begin(),title[t].end());
        author[a].push_back(ID);
        sort(author[a].begin(),author[a].end());
        splitString(k,b," ");
        for (int i=0;i<b.size();i++)    {
            keyword[b[i]].push_back(ID);
            sort(keyword[b[i]].begin(),keyword[b[i]].end());
        }
        publisher[p].push_back(ID);
        sort(publisher[p].begin(),publisher[p].end());
        year[y].push_back(ID);
        sort(year[y].begin(),year[y].end());
    }
    scanf("%d",&n);
    while (n--) {
        scanf("%d: ",&select);
        getline(cin,st);
        switch(select)  {
            case 1: printVector(title,st);break;
            case 2: printVector(author,st);break;
            case 3: printVector(keyword,st);break;
            case 4: printVector(publisher,st);break;
            case 5: printVector(year,st);break;
        }
    }
    return 0;
}

void printVector(map<string,vector<int> > a, string s) {
    if (a.find(s)==a.end()) {
        printf("Not Found\n");
        return;
    }
    for (int i=0;i<a[s].size();i++) printf("%d\n",a[s][i]);
}

void splitString(string& a,vector<string>& b,string c)  {
    int pos1,pos2;
    pos1=0;
    pos2=a.find(c);
    while (string::npos!=pos2)  {
        b.push_back(a.substr(pos1,pos2-pos1));
        pos1=pos2+c.size();
        pos2=a.find(c,pos1);
    }
    if (pos1!=a.length())   b.push_back(a.substr(pos1));
}

