#include <bits/stdc++.h>
using namespace std;
struct node{
    int now,data,nex;
}nodes[100005],pp[100005];
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int f,n,k;
    node nnd;
    cin>>f>>n>>k;
    int ff=f;
    for (int i=0;i<n;i++)   {
        cin>>nnd.now>>nnd.data>>nnd.nex;
        nodes[nnd.now]=nnd;
    }
    int nn;
    for (nn=0;nn<n;nn++)   {
        pp[nn]=nodes[ff];
        ff=nodes[ff].nex;
        if (ff==-1) break;
    }
    nn++;
    for (int i=0;i<nn;i+=k)   {
        if (i+k>nn) break;
        reverse(pp+i,pp+i+k);
        int tadd=pp[i].nex;
        for (int j=i;j<i+k-1;j++) {
            pp[j].nex=pp[j+1].now;
        }
        if (i+k+k>nn)    pp[i+k-1].nex=tadd;
        else    pp[i+k-1].nex=pp[i+k+k-1].now;
    }
    for (int i=0;i<nn;i++){
        cout.fill('0');
        cout.width(5);
        cout<<pp[i].now<<' ';
        cout<<pp[i].data<<' ';
        if (pp[i].nex!=-1)  {
            cout.fill('0');
            cout.width(5);
        }
        cout<<pp[i].nex<<endl;
    }
    return 0;
}
























//#include <bits/stdc++.h>
//using namespace std;
//int node[100005][2],li[100005];
//int main()  {
//    int add,n,k,ad,da,ne;
//    scanf("%d%d%d",&add,&n,&k);
//    for (int i=0;i<n;i++)   {
//        scanf("%d%d%d",&ad,&da,&ne);
//        node[ad][0]=da;
//        node[ad][1]=ne;
//    }
//    int pp=add,i=0;
//    while (pp!=-1)   {
//        li[i++]=pp;
//        pp=node[pp][1];
//    }
//    li[i]=-1;
//    int cc=0;
//    while(cc+k<=i) {
//        reverse(li+cc,li+cc+k);
//        cc+=k;
//    }
//    for (int j=0;j<i-1;j++)
//        printf("%05d %d %05d\n",li[j],node[li[j]][0],li[j+1]);
//    printf("%05d %d -1\n",li[i-1],node[li[i-1]][0]);
//    return 0;
//}
