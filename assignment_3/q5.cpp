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
    Node* create();
    void inorder(Node*T);
    Node*getroot()
    {
        return root;
    }
};
Node* BinaryTree::create()
{
    int x;
    cout<<"\nenter data= ";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*p=new Node(x);
    cout<<"enter left data= ";
    p->left=create();
    cout<<"enter right data= ";
    p->right=create();
    return p;
}
void BinaryTree::inorder(Node*T)
{
    if(T==NULL)
    {
        return ;
    }
    inorder(T->left);
    cout<<T->data;
    inorder(T->right);
}
int main()
{
    BinaryTree bt;
    bt.create();
    bt.inorder(bt.getroot());
    
}