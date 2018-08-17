#include <bits/stdc++.h>
using namespace std;
void pr13radix(int n);
int main()  {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("#");
    pr13radix(a);
    pr13radix(b);
    pr13radix(c);
    cout<<endl;
    return 0;
}

void pr13radix(int n)   {
    int ans[10],i=0,cnt=0;
    fill(ans,ans+10,0);
    if (n==0)   {
        printf("00");
        return;
    }
    while (n)   {
        ans[cnt++]=n%13;
        n/=13;
    }
    for (i=9;ans[i]==0&&i>=0;i--);
    if (i==0)   {
        printf("0");
        switch(ans[0])  {
            case 10: ans[0]='A';break;
            case 11: ans[0]='B';break;
            case 12: ans[0]='C';break;
            default: ans[0]+='0';break;
        }
        printf("%c",ans[0]);
        return;
    }
    for (int j=i;j>=0;j--)  {
        switch(ans[j])  {
            case 10: ans[j]='A';break;
            case 11: ans[j]='B';break;
            case 12: ans[j]='C';break;
            default: ans[j]+='0';break;
        }
        printf("%c",ans[j]);
    }
}
