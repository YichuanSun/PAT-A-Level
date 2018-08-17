#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE=2005;
double poly1[MAX_SIZE],poly2[MAX_SIZE],ans[MAX_SIZE];
void polyin(double* p);
void polyout(double* p);
void polymul(double* p1,double* p2,double* p3);
int k1,k2,k3;
int main()  {
    polyin(poly1);
    polyin(poly2);
    polymul(poly1,poly2,ans);
    polyout(ans);
}

void polyin(double* p)  {
    int k,ex;
    double co;
    scanf("%d",&k);
    for (int i=0;i<k;i++)   {
        scanf(" %d %lf",&ex,&co);
        p[ex]=co;
    }
}

void polymul(double* p1,double* p2,double* p3)  {
    for (int i=0;i<MAX_SIZE;i++)  {
        for (int j=0;j<MAX_SIZE;j++)    {
            if (p1[i]*p2[j]!=0)   {
                p3[i+j]+=p1[i]*p2[j];
            }
        }
    }
}

void polyout(double* p) {
    int cnt=0;
    for (int i=0;i<MAX_SIZE;i++)
        if (p[i]!=0)    cnt++;
    cout<<cnt;
    for (int i=MAX_SIZE-1;i>=0;i--) {
        if (p[i]!=0)
            printf(" %d %.1lf",i,p[i]);
    }
}
