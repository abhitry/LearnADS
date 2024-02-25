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
    void crt();
    Node* create();
    Node* insert(Node*T,int x);
    Node*getroot()
    {
        return root;
    }
    void preorder(Node*);
};
void BST::preorder(Node*T)
{
    if(T==NULL)
    {
        return ;
    }
    cout<<T->data;
    preorder(T->left);
    preorder(T->right);
}
void BST::crt()
{
    root=create();
}
Node* BST::create()
{
    int x;
    cout<<"enter data= ";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*T=new Node(x);
    T->left=create();
    T->right=create();
    return T;
}

bool partition(Node*T,long long  low,long long  up)
{
    if(T==NULL)
    {
        return true;
    }
    if(T->data<=low || T->data>=up)
    {
        return false;
    }
    return partition(T->left,low,T->data) && partition(T->right,T->data,up);
    
}
int main()
{
    BST b1;
    b1.crt();
    b1.preorder(b1.getroot());
    cout<<partition(b1.getroot(),INT_MIN,INT_MAX);
}