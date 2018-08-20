#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1005];
int main()  {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    gets(s);
    int ans=0,temp=0,cnt=0;
    int ans1=0,temp1=0,cnt1=0;
    for (int i=0;i<strlen(s);i++)    {
        temp=i;
        cnt=1;
        while (temp-cnt>=0&&temp+cnt<strlen(s))  {
            if (s[temp+cnt]==s[temp-cnt])
                cnt++;
            else    break;
        }
        if (cnt>ans)    ans=cnt;
        temp1=i;
        cnt1=0;
        while (temp1-cnt1>=0&&temp1+cnt1+1<strlen(s))  {
            if (s[temp1+cnt1+1]==s[temp1-cnt1])
                cnt1++;
            else    break;
        }
        if (cnt1>ans1)    ans1=cnt1;
    }
    if (2*ans-1>ans1*2) printf("%d\n",2*ans-1);
    else    printf("%d\n",2*ans1);
    return 0;
}
