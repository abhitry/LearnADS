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
class BinaryTree
{
    Node*root;
    public:
    BinaryTree()
    {
        root=NULL;
    }
    void creat();
    void preorder(Node*T);
    Node* create();
    Node* getroot()
    {
        return root;
    }
    int check_bst(Node*T);    
};
void BinaryTree::creat()
{
    root=create();
}
Node* BinaryTree ::create()
{
    int x;
    cout<<"\nenter data=";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*T=new Node(x);
    cout<<"enter left data: "<<x;
    T->left=create();
    cout<<"enter right data: "<<x;
    T->right=create();
    return T;
}
void BinaryTree :: preorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    cout<<T->data<<" ";
    preorder(T->left);
    preorder(T->right);
}
int BinaryTree::check_bst(Node*T)
{
    if(T==NULL)
    {
        cout<<"empty lsit";
        return 1;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 1;
    }
    if(T->left==NULL)
    {
        if(T->right->data<T->data)
        {
            return 0 ;
        }
        else {
            return check_bst(T->right);
        }
    }
    if(T->right==NULL)
    {
        if(T->left->data>T->data)
        {
            return 0 ;
        }
        else
        {
            return check_bst(T->left);
        }
    }
    if(T->left!=NULL && T->right!=NULL)
    {
        if(T->left->data >T->data)
        {
            return 0;
        }
        if(T->right->data<T->data)
        {
            return 0;
        }
    }
    int res;
    res=check_bst(T->left);
    if(res==0)
    {
        return 0;
    }
    res=check_bst(T->right);
    return res;
}
int main()
{
    BinaryTree bt;
    bt.creat();
    bt.preorder(bt.getroot());
    int c=bt.check_bst(bt.getroot());
    if(c==0)
    {
        cout<<"\nnot a bst";
    }
    else{
        cout<<"\nbst";
    }
}
