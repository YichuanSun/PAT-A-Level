/*
�����Ҳ��ᣬ�����ҶԹ������յò��ã���֪��ʲô�����Ӧ����ô����
���о����Ҷ��ַ����������Ŀһֱ���ղ��ã����Ǹ��̰塣
����������ݽṹ��û�뵽������㷨��Ҳû�뵽�����ԣ���gg��
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> a={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> b={"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
vector<int> tnum;
vector<string> media;
int main()  {
    int n;
    scanf("%d",&n);
    if (n<0)    {
        printf("Fu ");
        n=-n;
    }
    if (n==0)   {
        printf("ling\n");
        return 0;
    }
    else if (n==100000)  {
        printf("yi Shi Wan\n");
        return 0;
    }
    else if (n==1000000)    {
        printf("yi Bai Wan\n");
        return 0;
    }
    else if (n==10000000)   {
        printf("yi Qian Wan\n");
        return 0;
    }
    while (n!=0)    {
        tnum.push_back(n%10);
        n/=10;
    }
    unsigned e=0;
    for (;e<tnum.size()&&tnum[e]==0;e++);
    for (unsigned i=e;i<tnum.size();i++)    {
        if (i!=0&&(tnum[i]!=0||i==4||i==8))
            media.push_back(b[i]);
        media.push_back(a[tnum[i]]);
    }
    for (unsigned i=media.size()-1;i>=0;i--)   {
        if (i!=media.size()-1)    printf(" ");
        int cnt=0;
        while (i>=0&&media[i]=="ling")  {
            i--;
            cnt++;
        }
        if (cnt!=0&&media[i]!="Wan")    printf("ling ");
        cout<<media[i];
        if (i==0)   break;
    }
    printf("\n");
    return 0;
}
