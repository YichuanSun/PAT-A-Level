#include <iostream>
using namespace std;
const int maxn = 31;

int n, index = 0;
int pre[maxn], post[maxn];
bool flag = true;

struct Node {
	int data;
	Node *lchild, *rchild;
} *root;

Node *create(int preL, int preR, int postL, int postR){
	if (preL > preR) return NULL;//������ͷ���NULL
	Node *node = new Node;//���������
	node->data = pre[preL];
	node->lchild = NULL;
	node->rchild = NULL;
	if (preL == preR)
		return node;//��ֻ��һ���ڵ���ôֱ�ӷ��ؼ���
	int k = 0;
	for (k = preL + 1; k <= preR; k++)
		if (pre[k] == post[postR - 1]) break;//��ǰ�����Һ�������������λ��
	if (k - preL > 1){
		node->lchild = create(preL + 1, k - 1, postL, postL + k - preL - 2);
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	else{
		flag = false;
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	return node;
}

void inOrder(Node *node){
	if (node == NULL) return;
	inOrder(node->lchild);
	if (index < n - 1)
		cout << node->data << " ";
	else cout << node->data << endl;
	index++;
	inOrder(node->rchild);
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pre[i];
	for (int i = 0; i < n; ++i) cin >> post[i];
	root = create(0, n - 1, 0, n - 1);
	if (flag) cout << "Yes\n";
	else cout << "No\n";
	inOrder(root);
	return 0;
}
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

//��������д������
//#include <bits/stdc++.h>
//#define N 105
//using namespace std;
//typedef struct bt{
//    int data;
//    bt *lc,*rc;
//}bt;
//int pre[N],post[N],n;
//bt* prePostBuildTree(int pre[],int post[],int n)  {
//    if (n<=0)   return nullptr;
//    int i=0;
//    while (pre[i]!=post[n-1])   i++;
//    bt *nw=new bt;
//    nw->data=post[n-1];
//    if (i==0)   {
//        nw->lc=prePostBuildTree(pre+1,post,i+1);
//        nw->rc=prePostBuildTree(pre+i+1,post+i+1,n-i-1);
//    }
//    else {
//        nw->lc=prePostBuildTree(pre+1,post,i+1);
//
//    }
//    return nw;
//}
//int main()  {
//    cin>>n;
//    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
//    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
//    buildTree();
//    return 0;
//}
