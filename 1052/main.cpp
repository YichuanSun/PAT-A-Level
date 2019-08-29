#include <bits/stdc++.h>
#define N 100005
using namespace std;
class node{
public:
    int add,data,ne;
    node(): add(-2),data(-2),ne(-2) {}
    node(int a,int b,int c): add(a),data(b),ne(c) {}
};
bool cmp(node a,node b) {return a.data<b.data;}
node s[N];
int main()  {
    int n,be,a,b,c;
    cin>>n>>be;
    if (n==0)   {   //不存在特判的情况，而是有节点不在链表中
        cout<<"0 -1\n";
        return 0;
    }
    for (int i=0;i<n;i++)   {
        cin>>a>>b>>c;
        s[i]=node(a,b,c);
    }
    sort(s,s+n,cmp);
    printf("%d %05d\n",n,s[0].add);
    for (int i=0;i<n-1;i++)
        printf("%05d %d %05d\n",s[i].add,s[i].data,s[i+1].add);
    printf("%05d %d -1\n",s[n-1].add,s[n-1].data);
    return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//struct node{
//    int now,key,next;
//}nodes[100005];
//
//bool cmp(node a,node b) {
//    return a.key<b.key;
//}
//
//int main()  {
//    //ios::sync_with_stdio(false);
//    //cin.tie(0);
//    int n,ha,ad,k,ne;
//    cin>>n>>ha;
//    for (int i=0;i<n;i++)   {
//        cin>>ad;
//        cin>>nodes[i].key>>nodes[i].next;
//        nodes[i].now=ad;
//    }
//    sort(nodes,nodes+n,cmp);
//    for (int i=0;i<n-1;i++)   {
//        nodes[i].next=nodes[i+1].now;
//    }
//    nodes[n-1].next=-1;
//    if (n!=0)   printf("%d %05d\n",n,nodes[0].now);
//    else    printf("0 -1\n");
//    for (int i=0;i<n;i++)   {
//        if (i==n-1) printf("%05d %d -1\n",nodes[i].now,nodes[i].key);
//        else    printf("%05d %d %05d\n",nodes[i].now,nodes[i].key,nodes[i].next);
//    }
//    return 0;
//}
