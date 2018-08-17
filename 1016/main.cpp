#include <bits/stdc++.h>
using namespace std;
struct call{
    char name[21],status[10];
    int month,D,H,M,time,flag;
};
bool cmp(call c1,call c2)   {
    return strcmp(c1.name,c2.name)==0?c1.time<c2.time:strcmp(c1.name,c2.name)<0;
}
int main()  {
    int prize[25],N,cnf=0;
    prize[24]=0;
    vector<call> v;
    for (int i=0;i<24;i++)  {
        scanf("%d",&prize[i]);
        prize[24]+=prize[i];
    }
    scanf("%d",&N);
    call B[N];
    for (int i=0;i<N;i++)   {
        scanf("%s %d:%d:%d:%d %s",B[i].name,&B[i].month,&B[i].D,&B[i].H,&B[i].M,B[i].status);
        B[i].time=B[i].D*24*60+B[i].H*60+B[i].M;
        if (strcmp(B[i].status,"on-line")==0)
            B[i].flag=1;
        else
            B[i].flag=0;
    }
    sort(B,B+N,cmp);
    for (int i=1;i<N;i++)   {
        if (strcmp(B[i].name,B[i-1].name)==0)
        if (B[i-1].flag&&!B[i].flag)    {
            v.push_back(B[i-1]);
            v.push_back(B[i]);
            i++;
        }
    }
    char name[21];
    strcpy(name,v[0].name);
    printf("%s %02d\n",v[0].name,v[0].month);
    double TotalSum=0;
    for (int i=0;i<v.size();i+=2)    {
        if (strcmp(name,v[i].name)==0)  cnf=1;
        else    {
            cnf=0;
            strcpy(name,v[i].name);
        }
        if (cnf==0) {
            printf("Total amount: $%.2lf\n", TotalSum);
            TotalSum = 0;
            printf("%s %02d\n", v[i].name, v[i].month);
        }
        int p=0;
        double sum=0;
        if (v[i].H<v[i+1].H||v[i].D<v[i+1].D)   {
            sum+=prize[v[i].H]*(60-v[i].M)+prize[v[i+1].H]*v[i+1].M;
            if (v[i].D<v[i+1].D)    {
                for (int j=v[i].H+1;j<24;j++)   p+=prize[j];
                for (int j=0;j<v[i+1].H;j++)  p+=prize[j];
                p+=(v[i+1].D-v[i].D-1)*prize[24];
            }
            else
                for (int j=v[i].H+1;j<v[i+1].H;j++)
                    p+=prize[j];
            sum+=p*60;
        }
        else    sum+=prize[v[i].H]*(v[i+1].M-v[i].M);
        sum/=100;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", v[i].D, v[i].H, v[i].M, v[i+1].D, v[i+1].H, v[i+1].M, v[i+1].time-v[i].time, sum);
        TotalSum+=sum;
    }
    printf("Total amount: $%.2lf\n", TotalSum);
    return 0;
}
