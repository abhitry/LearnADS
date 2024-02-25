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
    int  findmin(Node*T);
    int findmax(Node*T);
    
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
int BinaryTree:: findmin(Node*T)
{
    if(T==NULL)
    {
        return INT_MAX;
    }
    int value,cmin,rmin;
    value=T->data;
    cmin=findmin(T->left);
    rmin=findmin(T->right);
return min(value,min(cmin,rmin));
}
int BinaryTree::findmax(Node*T)
{
    if(T==NULL)
    {
        return INT_MIN;
    }
    int value,cmax,rmax;
    value=T->data;
    cmax=findmax(T->left);
    rmax=findmax(T->right);
return (max(value,max(cmax,rmax)));
}
int main()
{
    BinaryTree bt;
    bt.creat();
    bt.preorder(bt.getroot());
    cout<<endl<<"minimum is = "<<bt.findmin(bt.getroot());
    cout<<endl<<"maximum is = "<<bt.findmax(bt.getroot());

}