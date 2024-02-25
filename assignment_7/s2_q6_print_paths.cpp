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
void print_paths(Node*T,vector<int>v,int t,int sum)
{
    if(T==NULL)
    {
        return;
    }
    v.push_back(T->data);
    sum=sum+T->data;
    if(T->left==NULL && T->right==NULL)
    {
        if(sum==t)
        {
            for(int j=0;j<v.size();j++)
            {
                cout<<v[j]<< " ";
            }
            cout<<endl;
            v.clear();
        }
        else{
            v.pop_back();
            sum=sum-T->data;
        }
    }
    print_paths(T->left,v,t,sum);
    print_paths(T->right,v,t,sum);
}
int main()
{
    BinaryTree bt;
    bt.creat();
    int target;
    cout<<"enter target to get sum- ";
    cin>>target;
    vector<int>v;
    print_paths(bt.getroot(),v,target,0);
    
}