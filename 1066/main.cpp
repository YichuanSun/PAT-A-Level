#include <bits/stdc++.h>
using namespace std;
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode  {
    int data,height;
    AVLTree left;
    AVLTree right;
};
int getHeight(AVLTree a);
AVLTree lrot(AVLTree a);
AVLTree rrot(AVLTree a);
AVLTree lrrot(AVLTree a);
AVLTree rlrot(AVLTree a);
AVLTree Insert(AVLTree T,int x);
int main()  {
    int n,t;
    cin>>n;
    AVLTree root=nullptr;
    for (int i=0;i<n;i++)   {
        cin>>t;
        root=Insert(root,t);
    }
    cout<<root->data<<endl;
    return 0;
}

AVLTree Insert(AVLTree T,int x) {
    if (!T) {
        T=new AVLNode;
        T->data=x;
        T->height=1;
        T->right=T->left=NULL;
    }
    else if (x<T->data) {
        T->left=Insert(T->left,x);
        if (getHeight(T->left)-getHeight(T->right)==2)  {
            if (x<T->left->data)
                T=lrot(T);
            else
                T=lrrot(T);
        }
    }
    else if (x>T->data) {
        T->right=Insert(T->right,x);
        if (getHeight(T->left)-getHeight(T->right)==-2) {
            if (x>T->right->data)
                T=rrot(T);
            else
                T=rlrot(T);
        }
    }
    T->height=max(getHeight(T->left),getHeight(T->right))+1;
    return T;
}

AVLTree lrot(AVLTree a) {
    AVLTree b=a->left;
    a->left=b->right;
    b->right=a;
    a->height=max(getHeight(a->left),getHeight(a->right))+1;
    b->height=max(getHeight(b->left),a->height)+1;
    return b;
}

AVLTree rrot(AVLTree a) {
    AVLTree b=a->right;
    a->right=b->left;
    b->left=a;
    a->height=max(getHeight(a->left),getHeight(a->right))+1;
    b->height=max(getHeight(b->left),a->height)+1;
    return b;
}

AVLTree lrrot(AVLTree a)    {
    a->left=rrot(a->left);
    return lrot(a);
}

AVLTree rlrot(AVLTree a)    {
    a->right=lrot(a->right);
    return rrot(a);
}

int getHeight(AVLTree a)    {
    int hl,hr;
    if (a)  {
        hl=getHeight(a->left);
        hr=getHeight(a->right);
        return max(hl,hr)+1;
    }
    else    return 0;
}
