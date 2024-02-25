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
    Node*getroot()
    {
        return root;
    }
    void create();
    void copy(Node*T);
    Node*copy_rec(Node*);
    void insert(int x);
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
        else
        {
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
void  inorder(Node*T)
{   
    if(T==NULL)
    {
        return;
    }
    inorder(T->left);
    cout<<T->data<<" ";
    inorder(T->right);
}
void BST::create()
{
    int x;
    while(1)
    {
        cout<<"enterr data= ";
        cin>>x; 
        if(x==0)
        {
            break;
        }
        insert(x);
    }
}
Node*BST::copy_rec(Node*T)
{
    if(T==NULL)
    {
        return NULL;
    }
    Node*Q=new Node(T->data);
    Q->left=copy_rec(T->left);
    Q->right=copy_rec(T->right);
    return Q;
}
void BST::copy(Node*T)
{
    root=copy_rec(T);
}
int main()
{
    BST b;
    b.create();
    inorder(b.getroot());
    cout<<endl;
    BST c;
    c.copy(b.getroot());
    inorder(c.getroot());
}
