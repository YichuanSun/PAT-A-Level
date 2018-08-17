#include <bits/stdc++.h>
using namespace std;
int wins(float b[][3],int i);
int main()  {
    float bet[3][3],ans=1;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            scanf("%f",&bet[i][j]);
    for (int i=0;i<3;i++)   {
        int col;
        col=wins(bet,i);
        switch(col) {
            case 0: cout<<'W';break;
            case 1: cout<<'T';break;
            case 2: cout<<'L';break;
        }
        cout<<' ';
        ans*=bet[i][col];
    }
    printf("%.2f\n",(ans*0.65-1)*2);
    return 0;
}

int wins(float b[][3],int i)    {
    if (b[i][0]>b[i][1])    {
        if (b[i][0]>b[i][2])    return 0;
        else    return 2;
    }
    else    {
        if (b[i][1]>b[i][2])    return 1;
        else    return 2;
    }
}
