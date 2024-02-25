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
int height(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    return max(height(T->left),height(T->right))+1;
}
bool Balanced(Node*T)
{
    if(T==NULL ||( T->left==NULL && T->right==NULL))
    {
        return 1;
    }   
    int l=Balanced(T->left);
    int r=Balanced(T->right);
    int diff=0;
    if(abs(height(T->left)-height(T->right))<=1)
    {
        diff=1;
    }
    return l&&r&&diff;
}
int main()
{
    BinaryTree bt;
    bt.creat();
    cout<<Balanced(bt.getroot());
}