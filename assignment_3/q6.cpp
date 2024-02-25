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
class BinaryTree
{
    Node*root;
    public:
    BinaryTree()
    {
        root=NULL;
    }
    void create();
    Node* getroot()
    {
        return root;
    }
};
Node* creat()
{
    int x;
    cout<<"enter data= ";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*p=new Node(x);
    cout<<"enter left data:\n";
    p->left=creat();
    cout<<"enter right data:\n";
    p->right=creat();
    return p;
}
int check(Node*p,Node*q)
{
    if(p==NULL && q==NULL)
    {
        return 1;
    }
    if(p==NULL)
    {
        return 0;
    }
    if(q==NULL)
    {
        return 0;
    }
    int res;
    res =check(p->left,q->left);
    if(p->data!=q->data)
    {
        res= 0;
    }
    if(res==1)
    {
        res=check(p->right,q->right);
    }
    return res;
}
void BinaryTree::create()
{
    root=creat();
}
int main()
{
    BinaryTree bt,ct;
    bt.create();
    ct.create();
    cout<<check(bt.getroot(),ct.getroot());
}