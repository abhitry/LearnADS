#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*left,*right;
    Node()
    {
        data=0;
        left=right=NULL;
    }
    Node(int a)
    {
        data=a;
        left=right=NULL;
    }
};
class BST
{
    Node*root;
    public:
    BST()
    {
        root=NULL;
    }
    void create();
    void insert(int x);
    Node*getroot()
    {
        return root;
    }
};
class TBTNode
{
    public:
    int data,child,lbit,rbit;
    TBTNode*left,*right;
    TBTNode()
    {
        data=child=-1;
        lbit=rbit=0;
        left=right=NULL;
    }
    TBTNode(int a)
    {
        data=a;
        child=-1;
        lbit=rbit=0;
        right=left=NULL;
    }
};
class TBT
{
    TBTNode*root;
    public:
    TBT()
    {
        root=new TBTNode(-1);
        root->left=root->right=root;
        root->lbit=root->rbit=1;
    }
    void copy(Node*T);
    TBTNode* copy_rec(Node*T);
    void convert();
    void inorder_rec(TBTNode*T,TBTNode* inseq[],int &n);
    void final_convert(TBTNode* inseq[],int n);
    void preorder();
    TBTNode* preorder_succ(TBTNode*);
};
void BST::insert(int x)
{
    Node*T=root;
    Node*p=NULL;
    if(root==NULL)
    {
        root=new Node(x);
        return;
    }
    while(T!=NULL)
    {
        p=T;
        if(x<T->data)
        {
            T=T->left;
        }
        else if(x>T->data)
        {
            T=T->right;
        }
        else{
            cout<<"duplicate";
            return;
        }
    }
    if(x<p->data)
    {
        p->left=new Node(x);
    }
    else{
        p->right=new Node(x);
    }
}
void BST:: create()
{
    int x;
    while(1)
    {
        cout<<"enter dtaa=";
        cin>>x;
        if(x==0)
        {
            break;
        }
        insert(x);
    }
}
void inorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    inorder(T->left);
    cout<<T->data<<" ";
    inorder(T->right);
}
TBTNode* TBT::copy_rec(Node*T)
{
    if(T==NULL)
    {
        return NULL;
    }
    TBTNode*Q=new TBTNode(T->data);
    Q->left=copy_rec(T->left);
    Q->right=copy_rec(T->right);
    return Q;
}
void TBT::copy(Node*T)
{
    root->left=copy_rec(T);
}
void TBT::inorder_rec(TBTNode*T,TBTNode* inseq[],int &n)
{
    if(T==NULL)
    {
        return;
    }
    inorder_rec(T->left,inseq,n);
    if(T->left!=NULL)
    {
        T->left->child=0;
    }
    inseq[n]=T;
    n++;
    inorder_rec(T->right,inseq,n);
    if(T->right!=NULL)
    {
        T->right->child=1;
    }
}
void TBT::final_convert(TBTNode*inseq[],int n)
{
    TBTNode*T=inseq[0];
    T->left=root;
    T->lbit=0;
    if(T->right!=NULL)
    {
        T->right=inseq[1];
        T->rbit=1;
    }
    else{
        T->right=inseq[1];
        T->rbit=0;
    }

    T=inseq[n-1];
    T->right=root;
    T->rbit=0;
    if(T->left!=NULL)
    {
        T->left=inseq[n-2];
        T->lbit=1;
    }
    else{
        T->left=inseq[n-2];
        T->lbit=0;
    }

    for(int i=1;i<=n-2;i++)
    {
        T=inseq[i];
        if(T->left==NULL)
        {
            T->left=inseq[i-1];
            T->lbit=0;
        }
        else{
            T->lbit=1;
        }
        if(T->right==NULL)
        {
            T->right=inseq[i+1];
            T->rbit=0;
        }
        else{
            T->rbit=1;
        }
    }
}
void TBT::convert()
{
    TBTNode*inseq[30];
    int n=0;
    inorder_rec(root->left,inseq,n);
    root->left->child=0;
    final_convert(inseq,n);
    cout<<endl;
    preorder();
    // n--;
    // cout<<"abgish";
    // while(n>=0)
    // {
    //     cout<<inseq[n]->child<<" ";
    //     cout<<inseq[n]->data<< endl;
    //     n--;
    // }
}
TBTNode*TBT::preorder_succ(TBTNode* T)
{
    if(T->lbit==1)
    {
        T=T->left;
        return T;
    }
    else if(T->rbit==1)
    {
        T=T->right;
        return T;
    }
    else{
        while(T->rbit==0)
        {
            T=T->right;
        }
        T=T->right;
    }
    return T;
    
}
void TBT:: preorder()
{
    TBTNode*Temp=root->left;
    while(Temp!=root)
    {
        cout<<Temp->data<<" ";
        Temp=preorder_succ(Temp);
    }
}
int main()
{
    BST bst;
    bst.create();
    inorder(bst.getroot());
    TBT tbt;
    tbt.copy(bst.getroot());
    tbt.convert();
}