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
void inorder(Node*T,int &count,int k)
{
    if(T==NULL)
    {
        return;
    }  
    inorder(T->left,count,k);
    count++;
    if(count==k)
    {
        cout<<T->data<<endl;
        return;
    }
    inorder(T->right,count,k);
}
int main()
{
    BinaryTree bt;
    bt.creat();
    int k;
    cout<<"enter k value = ";
    cin>>k;
    int count=0;
    inorder(bt.getroot(),count,k);   
}