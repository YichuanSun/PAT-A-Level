#include <bits/stdc++.h>
#define N 1005
using namespace std;
struct bt{
    int data;
    bt *lc,*rc;
};
int a[N],b[N];
bool cmpltoh(int a,int b)   {return a<=b;}
bool cmphtol(int a,int b)   {return a>=b;}
void pret(bt* root)    {
    printf("%d ",root->data);
    pret(root->lc);
    pret(root->rc);
}
bt* preInBuildTree(int pre[],int in[],int n);
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   {cin>>a[i];b[i]=a[i];}
    sort(b,b+n);
    preInBuildTree(a,b,n);
    return 0;
}
bt* preInBuildTree(int pre[],int in[],int n)   {
    if (n<=0)   return nullptr;
    int i=0;
    while (pre[0]!=in[i])   i++;
    bt* nw=new bt;
    nw->data=pre[0];
    nw->lc=preInBuildTree(pre+1,in,i);
    nw->rc=preInBuildTree(pre+i+1,in+i+1,n-i-1);
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
