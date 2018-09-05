#include <bits/stdc++.h>
#define N 1005
#define INF 1000000000
using namespace std;
struct gss{
    int num;
    double mi,av;
};
vector<gss> mmp;
int g[N][N],d[N];
bool used[N];
int n,m,k,ds;
void dijkstra(int i);
void exic(char* a,int& s);
bool cmp(gss a,gss b)   {
    if (a.mi==b.mi) {
        if (a.av==b.av) return a.num<b.num;
        return a.av<b.av;
    }
    return a.mi>b.mi;
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(g[0],g[0]+N*N,INF);
    int t,ta,tb,ansnum;
    double ansav,ansmin;
    char *a=new char[4],*b=new char[4];
    cin>>n>>m>>k>>ds;
    for (int i=0;i<k;i++)   {
        cin>>a>>b>>t;
        exic(a,ta);
        exic(b,tb);
        g[ta][tb]=t;
        g[tb][ta]=t;
    }
    for (int i=1;i<=m;i++)  {
        dijkstra(i+n);
        double mi=INF,sum=0;
        int q;
        for (q=1;q<=n;q++)  {
            sum+=d[q];
            if (d[q]>ds)    break;
            if (d[q]<mi)    mi=d[q];
        }
        gss tgs;
        tgs.num=i+n;
        if (q!=n+1) tgs.av=tgs.mi=-1;
        else    {
            tgs.av=sum/n;
            tgs.mi=mi;
        }
        mmp.push_back(tgs);
    }
    sort(mmp.begin(),mmp.end(),cmp);
    int k=0;
    while (k<mmp.size()&&mmp[k].mi==-1)   k++;
    if (k==mmp.size())  cout<<"No Solution"<<endl;
    else    {
        cout.setf(ios::fixed);
        cout<<'G'<<mmp[k].num-n<<endl;
        cout<<setprecision(1)<<mmp[k].mi<<' ';
        cout<<mmp[k].av+0.05<<endl;
    }
    return 0;
}

void dijkstra(int i) {
    fill(used,used+N,false);
    fill(d,d+N,INF);
    d[i]=0;
    while (true)    {
        int v=-1;
        for (int u=1;u<=n+m;u++) {
            if (!used[u]&&(v==-1||d[u]<d[v]))
                v=u;
        }
        if (v==-1)  break;
        used[v]=true;
        for (int u=1;u<=n+m;u++)  {
            //cout<<d[u]<<' '<<d[v]<<' '<<g[v][u]<<endl;
            d[u]=min(d[u],d[v]+g[v][u]);
        }
    }
}

void exic(char* a,int& s)   {
    if (strlen(a)==3)   s=10;
    else if (strlen(a)==2)  s=a[1]-'0'+n;
    else if (strlen(a)==1)  s=a[0]-'0';
}
