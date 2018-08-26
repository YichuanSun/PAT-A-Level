#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *lc,*rc;
};
stack<int> st;
vector<int> ans;
int preo[35],io[35],n;
node* buildTree(int io[],int preo[],int root);
void postorder(node* root);
int main()  {
    int cnt=0,t,cc=0;
    string order;
    cin>>n;
    while (cnt<n||!st.empty())   {
        cin>>order;
        if (order[1]=='u')  {
            cin>>t;
            st.push(t);
            preo[cnt++]=t;
        }
        else if (order[1]=='o') {
            io[cc++]=st.top();
            st.pop();
        }
    }
    node* root=buildTree(io,preo,n);
    postorder(root);
    cout<<ans[0];
    for (unsigned i=1;i<ans.size();i++)
        cout<<' '<<ans[i];
    cout<<endl;
    return 0;
}

node* buildTree(int io[],int preo[],int s) {
    if (s<=0)   return nullptr;
    int i=0;
    while (io[i]!=*preo)  i++;
    node* newnode=new node;
    newnode->data=io[i];
    newnode->lc=buildTree(io,preo+1,i);
    newnode->rc=buildTree(io+i+1,preo+i+1,s-i-1);
    return newnode;
}

void postorder(node* root)  {
    if (root==nullptr)  return;
    postorder(root->lc);
    postorder(root->rc);
    ans.push_back(root->data);
}


