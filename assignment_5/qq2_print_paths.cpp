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
    void print_path(Node*T,int arr[],int i,int &j);
    
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
void BinaryTree::print_path(Node*T,int arr[],int i,int &k)
{
    if(T==NULL)
    {
        return ;
    }
    arr[i]=T->data;
    if(T->left==NULL &&T->right==NULL)
    {   cout<<" Path no "<<k<<" = ";
        k++;
        for(int j=0;j<=i;j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        return ;
    }
    print_path(T->left,arr,i+1,k);
    print_path(T->right,arr,i+1,k);
return ;
}
int main()
{
    BinaryTree bt;
    bt.creat();
   //12 bt.preorder(bt.getroot());
    cout<<endl;
    int arr[30];
    int j=1;
    bt.print_path(bt.getroot(),arr,0,j);
}
