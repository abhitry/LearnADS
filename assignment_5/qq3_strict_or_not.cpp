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
    int check_sbt(Node*T);

    
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
int BinaryTree::check_sbt(Node*T)
{
    if(T==NULL)
    {
        cout<<"empty tree\n";
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 1;
    }
    if(T->left==NULL)
    {
        return 0 ;
    }
    if(T->right==NULL)
    {
        return 0;
    }
    int res;
    res=check_sbt(T->left);
    if(res==0)
    {
        return 0;
    }
    res=check_sbt(T->right);
    return res ;
}
int main()
{
    BinaryTree bt;
    bt.creat();
    bt.preorder(bt.getroot());
    cout<<endl;
    int s=bt.check_sbt(bt.getroot());
    if(s==0)
    {
        cout<<"not strict binary ";
    }
    else{
        cout<<"strict binary tree";
    }
}