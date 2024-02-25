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
Node* createfromseq(int preorder[],int inorder[],int start,int end)
{
    if(start > end)
    {
        return NULL;
    }
    Node*T;
    T=new Node(preorder[preindex]);
    preindex++;
    if(start==end)
    {
        return T;
    }
    //search 
}
int main()
{
    int preorder[30]={10,17,7,9,19,13,8,15};
    int inorder[30]={7,9,17,10,13,8,19,15};
    createfromseq(preorder,inorder,0,7);
    
}