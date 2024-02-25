#include<iostream>
using namespace std;
class Node
{
    public:
    Node*left,*right;
    int data;
    Node()
    {
        left=right=NULL;
        data=0;
    }
    Node(int a)
    {
        left=right=NULL;
        data=a;
    }
};
class BT
{
    Node*root;
    public:

    BT()
    {
        root=NULL;
    }
    void create();
    Node*getroot()
    {
        return root;
    }
    Node* mergeTrees(Node*p,Node*q);
    void merge(Node*p,Node*q);
};
Node*create_rec()
{
    int x;
    cout<<"enter value=";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*T=new Node(x);
    T->left=create_rec();
    T->right=create_rec();
    return T;
}
void BT::create()
{
    root=create_rec();
}
void preorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    cout<<T->data;
    preorder(T->left);
    preorder(T->right);
}
void BT::merge(Node*p,Node*q){
    root=mergeTrees(p,q);
}
Node* BT::mergeTrees(Node*p,Node*q)
{
    if(p==NULL&&q==NULL)
    {
        return  NULL;
    }
    if(p==NULL)
    {
        return q;
    }
    if(q==NULL)
    {
        return p;
    }
    p->data=+q->data;
    p->left=mergeTrees(p->left,q->left);
    p->right=mergeTrees(p->right,q->right);
    return p;
}
int main()
{
    BT b1,b2;
    b1.create();
    cout<<"enter second=-";
    b2.create();
    preorder(b1.getroot());
    cout<<endl;
    preorder(b2.getroot());
    cout<<endl;
    b1.merge(b1.getroot(),b2.getroot());
    preorder(b1.getroot());
}