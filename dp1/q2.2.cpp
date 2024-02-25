#include<iostream>
#include<stack>
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
    void preorder();
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
    if(x<T->data)
    {
        T->left=insert(T->left,x);
        return T;
    }
    if(x>T->data)
    {
        T->right=insert(T->right,x);
        return T;
    }
    return T;
}
void Tree::preorder()
{
    Node*T=root;
    stack<Node*>stk;
    while(T!=NULL)
    {
        stk.push(T);
        cout<<T->data<<" ";
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.top();
        stk.pop();
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            cout<<T->data<<" ";
            T=T->left;
        }
    }
}
void Tree::delet()
{
    int x;
    cout<<"enter data=";
    cin>>x;
    root=delete_rec(root,x);
}
Node*Tree::findmin(Node*T)
{
    if(T->left==NULL)
    {
        return T;
    }
    return findmin(T->left);
}
Node*Tree::delete_rec(Node*T,int x)
{
    if(T==NULL)
    {
        return T;
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
    if(T->left==NULL && T->right==NULL)
    {
        delete T;
        return NULL;
    }
    if(T->left==NULL)
    {
        Node*P=T->right;
        delete T;
        return P;
    }
    if(T->right==NULL)
    {
        Node*p=T->left;
        delete T;
        return p;
    }
    Node*p=findmin(T->right);
    T->data=p->data;
    T->right=delete_rec(T->right,p->data);
    return T;
}
int main()
{
    Tree T1;
    T1.create();
    T1.preorder();
    T1.delet();
    T1.preorder();
}