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
class Tree
{
    Node*root;
    public:
    Tree()
    {
        root=NULL;
    } 
    void create();
    void show(Node*);
    Node*insert(Node*,int);
    Node*getroot()
    {
        return root;
    }
    void delet();
    Node*delete_rec(Node*T,int x);
    Node*findmin(Node*T);
};
void Tree::create()
{
    int x;
    cout<<"enter data=";
    while(1)
    {
        cin>>x;
        if(x==0)
        {
            break;
        }
        root=insert(root,x);
    }
}
Node*Tree::insert(Node*T,int x)
{
    if(T==NULL)
    {
        return new Node(x);
    }
    if(T->data>x)
    {
        T->left=insert(T->left,x);
        return T;
    }
    if(T->data<x)
    {
        T->right=insert(T->right,x);
        return T;
    }
    return T;
}
void Tree:: show(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    cout<<T->data<<" ";
    show(T->left);
    show(T->right);
}
void Tree::delet()
{
    int x;
    cout<<"enter data to delete =";
    cin>>x;
    root=delete_rec(root,x);
}
Node*Tree::findmin(Node*T)
{
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;
}
Node*Tree::delete_rec(Node*T,int x)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(x<T->data)
    {
        T->left=delete_rec(T->left,x);
        return T;
    }
    if(x>T->data)
    {
        T->right=delete_rec(T->right,x);
        return T;
    }
    if(T->left ==NULL && T->right==NULL)
    {
        delete T;
        return NULL;
    }
    if(T->left==NULL)
    {
        Node*p=T->right;
        delete T;
        return p;
    }
    if(T->right==NULL)
    {
        Node*p=T->left;
        delete T;
        return p;
    }
    else{
        Node*p=findmin(T->right);
        T->data=p->data;
        T->right=delete_rec(T->right,p->data);
        return T;
    }
}
int main()
{
    Tree T1;
    T1.create();
    T1.show(T1.getroot());
    T1.delet();
    T1.show(T1.getroot());
}