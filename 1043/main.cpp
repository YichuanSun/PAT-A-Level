#include <bits/stdc++.h>
#define N 1005
#define MX 10000000
using namespace std;
struct bt{
    int data;
    bt *lc,*rc;
};
int a[N],mn=-MX,mx=MX,fg=0;
bt* buildTree(int a[],int n,bool cmp(int,int));
bool cmpltoh(int a,int b)   {return a<=b;}
bool cmphtol(int a,int b)   {return a>=b;}
void post(bt* root) {
    if (root==nullptr)   return;
    post(root->lc);
    post(root->rc);
    if (fg==0)  {cout<<root->data;fg=1;}
    else cout<<' '<<root->data;
}
bool jud(bt* t,bool cmp(int,int),int r) {
    if (t==nullptr) return true;
    bool b1,b2;
    b1=jud(t->lc,cmp,r);
    if (b1==false||(cmp(t->data,r)&&t->data!=r))  return false;
    r=t->data;
    b2=jud(t->rc,cmp,r);
    return b2;
}
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   cin>>a[i];
    bt* root1=buildTree(a,n,cmpltoh);   //虽然结果一样，但是树建出来是错的
    bt* root2=buildTree(a,n,cmphtol);
    if (jud(root1,cmpltoh,mn))  {cout<<"YES"<<endl;post(root1);cout<<endl;}
    else if (jud(root2,cmphtol,mx))   {cout<<"YES"<<endl;post(root2);cout<<endl;}
    else cout<<"NO"<<endl;
    return 0;
}
bt* buildTree(int a[],int n,bool cmp(int,int))    {
    if (n<=0)    return nullptr;
    int i=0;
    while (cmp(a[i],a[0])&&i<n)  i++;    //i-1是子树节点数
    bt* nw= new bt;
    nw->data=a[0];
    nw->lc=buildTree(a+1,i-1,cmp);
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
