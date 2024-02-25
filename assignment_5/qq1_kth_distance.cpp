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
    Node* print_k(Node*T,int k);
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
Node* BinaryTree::print_k(Node*T,int k)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(k==0)
    {
        cout<<T->data<<" ";
        return T;
    }
    print_k(T->left,k-1);
    print_k(T->right,k-1);
    return T;
}
int main()
{
    BinaryTree bt;
    bt.creat();
    bt.preorder(bt.getroot());
    int k;
    cout<<"enter distance k to print nodes= ";
    cin>>k;
    bt.print_k(bt.getroot(),k);
}