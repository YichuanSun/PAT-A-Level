#include <bits/stdc++.h>
#define N 50005
using namespace std;
int a[N],frq[N],usd[N];
vector<int> vr;
bool cmp(int a,int b)   {
    if (frq[a]==frq[b]) return a<b;
    return frq[a]>frq[b];
}
int main()  {
    int n,k,sml=-1;
    cin>>n>>k;
    for (int i=0;i<n;i++)   {
        cin>>a[i];
        if (i==0)   {continue;}
        frq[a[i-1]]++;
        if ((int)vr.size()<k)    {   //�������δ��
            if (usd[a[i-1]]==0)   {   //����������޸�ֵ
                vr.push_back(a[i-1]);
                usd[a[i-1]]=1;
            }
            else {
                sort(vr.begin(),vr.end(),cmp);
                if (!vr.empty())    sml=frq[vr.back()];
            }
        }
        else {  //��������
            if (usd[a[i-1]]==0)   {   //����������޸�ֵ
                if (frq[a[i-1]]>=sml)  {   //�������ֵ����Ƶ�����ڵ��������е���Сֵ
                    vr.push_back(a[i-1]);
                    sort(vr.begin(),vr.end(),cmp);
                    if (vr.back()!=a[i-1])    {usd[a[i-1]]=1;usd[vr.back()]=0;}
                    vr.pop_back();
                    if (!vr.empty())    sml=frq[vr.back()];
                }
            }
            else {  //����и�ֵ
                sort(vr.begin(),vr.end(),cmp);
                if (!vr.empty()) sml=frq[vr.back()];
            }
        }
        cout<<a[i]<<':';
        for (int j=0;j<(int)vr.size();j++)
            cout<<' '<<vr[j];
        cout<<endl;
    }
    return 0;
}
