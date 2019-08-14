//�����ע��������д��
/*
�����ҿ�ʼ���е�������⣬����������ˣ��ҽ�����
��1�� 2 3 4 6 7 5
 2 6 7 4 5 3 ��1��
 һ��Ҫ��ס��ǰ���Ǹ� �� �ҵ�
 ����˳����������� �� ���ı�
 ��˳����ôͨ��ȷ��������3��ǰ
 ���е�λ�ã���ô��֪����λ���
 �����ˣ���Ϊ3һ����1����������
 ������ô��ǰ���У�3֮ǰ1֮��
 �����о�����������3��5֮�䶼
 Ϊ��������һ���֣��ٵݹ鴦����
 �����������ֻ��һ����������ô
 ��ȷ�������������ң��Լ�����
 ��Ҳ��ǰ+��һ����Ψһȷ������ԭ��
 1 2 3 4
 2 4 3 1
 1Ϊ�������������ĸ���3��ǰ���е�λ��
 ��ô2����������3 4���������������ݹ�
 2ֻ��һ��ֱ�ӷ��أ�3 4��3�Ǹ���4����
 �������������ң��Լ�����������������ǲ���Ψһȷ��
*/

//�������ҷ��մ���д������
#include <bits/stdc++.h>
#define N 105
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
int pre[N],post[N],n,flag=1,cnt;
bt* prePostBuildTree(int prel,int prer,int postl,int postr)  {
    if (prel>prer)  return nullptr;     //�ڶ��μӵ�
    bt* nw=new bt;
    nw->data=pre[prel];
    nw->lc=nullptr;nw->rc=nullptr;
    if (prel==prer) return nw;          //�ڶ��μӵ�
    int i=prel+1;
    while (i<=prer&&pre[i]!=post[postr-1])  i++;
    if (i>prel+1)   {
        nw->lc=prePostBuildTree(prel+1,i-1,postl,postl+i-prel-2);
        nw->rc=prePostBuildTree(i,prer,postl+i-prel-1,postr-1);
    }
    else{
        flag=0;
        nw->rc=prePostBuildTree(i,prer,postl+i-prel-1,postr-1);
    }
    return nw;
}
void inOrderTraversal(bt* root) {
    if (root==nullptr)  return;
    inOrderTraversal(root->lc);
    printf("%d%c",root->data,(cnt++)==n-1?'\n':' ');
    inOrderTraversal(root->rc);
}
int main()  {
    cin>>n;
    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
    bt* root=prePostBuildTree(0,n-1,0,n-1);
    printf("%s\n",flag?"Yes":"No");
    inOrderTraversal(root);
    return 0;
}
