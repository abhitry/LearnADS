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
    void inorder(Node*T);
    Node* create();
    Node* getroot()
    {
        return root;
    }
    
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
void BinaryTree :: inorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    inorder(T->left);
    cout<<T->data<<" ";
    inorder(T->right);
}
int strict(Node*T)
{
    if(T==NULL)
    {
        return 1;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 1;
    }
    if(T->left==NULL)
    {
        if(T->right!=NULL)
        {
            return 0;
        }
    }
    if(T->right==NULL)
    {
        if(T->left!=NULL)
        {
            return 0;
        }
    }
    int res;
    res=strict(T->left);
    if(res==0)
    {
        return 0;
    }
    res=strict(T->right);
    return res;
}
int main()
{
    BinaryTree bt;
    bt.creat();
    cout<<strict(bt.getroot());
}
