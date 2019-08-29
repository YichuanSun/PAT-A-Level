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
