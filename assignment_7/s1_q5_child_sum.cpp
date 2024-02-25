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
    int childsum(Node*T);   
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
int BinaryTree::childsum(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 1;
    }
    if(T->left!=NULL && T->right!=NULL)
    {
        if(T->data!=T->left->data +T->right->data)
        {
            return 0;
        }
    }
    if(T->left==NULL)
    {
        if(T->data!=T->right->data)
        {
            return 0;
        }
        else
        {
            return childsum(T->right);
        }
    }
    if(T->right==NULL)
    {
        if(T->data !=T->left->data)
        {
            return 0;
        }
        else
        {
            return childsum(T->left);
        }
    }
    int res;
    res=childsum(T->left);
    if(res==0)
    {
        return 0;
    }
    res=childsum(T->right);
    return res;
}
int main()
{
    BinaryTree bt;
    bt.creat();
    bt.preorder(bt.getroot());
    if(bt.childsum(bt.getroot()))
    {
        cout<<"\nyes childsum";
    }
    else{
        cout<<"\nno childsum";
    }
}