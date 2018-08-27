#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int a = 1,left,now,right,ans = 0;
    while(n/a){
        left = n / (a*10);
        right = n % a;
        now = n / a % 10;
        if(now == 0) ans += left*a;
        else if(now == 1) ans += left*a + right + 1;
        else ans += (left+1)*a;
        a *= 10;
    }
    printf("%d",ans);
    return 0;
}
