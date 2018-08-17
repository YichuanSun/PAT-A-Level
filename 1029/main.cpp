//#include <bits/stdc++.h>
//using namespace std;
//vector<int> a;
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0),cout.tie(0);
//    int n1,te;
//    cin>>n1;
//    for (int i=0;i<n1;i++)  {
//        cin>>te;
//        a.push_back(te);
//    }
//    cin>>n1;
//    for (int i=0;i<n1;i++)  {
//        cin>>te;
//        a.push_back(te);
//    }
//    sort(a.begin(),a.end());
//    int spot=0;
//    if (a.size()&1) spot=a.size()/2;
//    else    spot=a.size()/2-1;
//    cout<<a[spot]<<endl;
//    return 0;
//}
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main()
{
    queue<int> a, b;
    int n, m, tnum, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tnum);
        a.push(tnum);
    }
    a.push(INT_MAX);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &tnum);
        b.push(tnum);
        if(cnt == (n + m - 1) / 2)
        {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front())
            a.pop();
        else
            b.pop();
        cnt++;
    }
    b.push(INT_MAX);
    for(; cnt < (n + m - 1) / 2; cnt++)
    {
        if(a.front() < b.front())
            a.pop() ;
        else
            b.pop() ;
    }
    printf("%d\n", min(a.front(), b.front()));
    return 0;
}
