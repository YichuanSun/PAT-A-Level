#include <bits/stdc++.h>
#define N 1005
using namespace std;
struct bt{
    int data;
    bt *lc,*rc;
};
int a[N];
bt* buildTree(int a[],int n,bool cmp(int,int));
bool cmpltoh(int a,int b)   {return a<=b;}
bool cmphtol(int a,int b)   {return a>=b;}
void pret(bt* root)    {
    printf("%d ",root->data);
    pret(root->lc);
    pret(root->rc);
}
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   cin>>a[i];
    bt* root1=buildTree(a,n,cmpltoh);
    pret(root1);
    bt* root2=buildTree(a,n,cmphtol);
    return 0;
}

bt*buildTree(int a[],int n,bool cmp(int,int))    {
    if (n<=0)    return nullptr;
    if (n==1)   {
        bt* nw=new bt;
        nw->data=a[0];
        nw->rc=nw->rc=nullptr;
        return nw;
    }
    int i=0;
    while (cmp(a[i],a[0]))  {
        i++;    //i-1是子树节点数
        //cout<<a[i]<<endl;
    }
    //cout<<"OK"<<endl;
    bt* nw= new bt;
    nw->data=a[0];
    if (i-1>0)
        nw->lc=buildTree(a+1,i-1,cmp);
    if (n-i>0)
        nw->rc=buildTree(a+i,n-i,cmp);
    return nw;
}






















//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> save;
//int n;
//bool isBST=true,flag;
//struct Node{
//    Node* left;
//    Node* right;
//    int val;
//};
//bool cmpltoh(int a,int b)  {return a<=b;}
//bool cmphtol(int a,int b)   {return a>=b;}
//Node* buildTree(int l,int r,bool cmp(int,int))    {
//    if (!isBST) return NULL;
//    if (l>r)   return NULL;
//    Node* root=new Node();
//    root->val=save[l];
//    int mid;
//    for (mid=l+1;mid<=r;mid++)
//        if (!cmp(save[mid],save[l]))
//            break;
//    root->left=buildTree(l+1,mid-1,cmp);
//    for (int i=mid;i<=r;i++)  {
//        if  (save[i]!=save[l]&&cmp(save[i],save[l]))    {
//            isBST=false;
//            return NULL;
//        }
//    }
//    root->right=buildTree(mid,r,cmp);
//    return root;
//}
//
//void posttr(Node* root) {
//    if (root==NULL) return;
//    posttr(root->left);
//    posttr(root->right);
//    if (flag==false)    {   //这种设flag打印树的方法很巧妙
//        cout<<root->val;
//        flag=true;
//    }
//    else    cout<<' '<<root->val;
//}
//
//int main()  {
//    int t;
//    cin>>n;
//    for (int i=0;i<n;i++)   {
//        cin>>t;
//        save.push_back(t);
//    }
//    Node* root=buildTree(0,n-1,cmpltoh);
//    if (isBST)  {
//        cout<<"YES"<<endl;
//        posttr(root);
//        cout<<endl;
//        return 0;
//    }
//    isBST=true;
//    root=buildTree(0,n-1,cmphtol);
//    if (isBST)  {
//        cout<<"YES"<<endl;
//        posttr(root);
//        cout<<endl;
//    }
//    else    cout<<"NO"<<endl;
//    return 0;
//}
