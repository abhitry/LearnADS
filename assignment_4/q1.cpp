#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    int child;
    int lbit,rbit;
    Node*left,*right;
    Node()
    {
        data=-1;
        child=-1;
        lbit=rbit=0;
        left=right=NULL;
    }
    Node(int a)
    {
        data=a;
        child=-1;
        lbit=rbit=0;
        left=right=NULL;
    }
};  
class TBT
{
    Node*root;
    public:
    TBT()
    {
        root=new Node(-1);
        root->left=root->right=root;
        root->lbit=root->rbit=1;
    }
    void create();
    void create_rec(Node*T,int);
    Node* getroot()
    {
        return root;
    }
    void inorder(Node*T);
    void preorder();
    Node* preorder_succ(Node*);
    Node* inorder_succ(Node*T);
    void inorder();
    void postorder();
    Node* postorder_succ(Node*T);
};
void TBT::create_rec(Node*father,int child)
{
   int x;
   cin>>x;
   if(x==0)
   {
        return ;
   }  
   Node *T=new Node(x);
   if(child==0)
   {
        T->left=father->left;
        T->right=father;
        T->child=0;
        father->left=T;
        father->lbit=1;
   }   
   else if(child==1)
   {
        T->right=father->right;
        T->left=father;
        T->child=1;
        father->right=T;
        father->rbit=1;
   } 
   cout<<"enter left data= ";                 
   create_rec(T,0);
   cout<<"enter right data= ";
   create_rec(T,1);
}
void TBT::create()
{
    create_rec(root,0);
}
void TBT::inorder(Node*T)
{
    if(T==root)
    {
        return;
    }
    if(T->lbit==1)
    {
        inorder(T->left);
    }
    cout<<T->data<<" ";
    if(T->rbit==1)
    {
        inorder(T->right);
    }
}
Node* TBT::preorder_succ(Node*T)
{
    if(T->lbit==1)
    {
        T=T->left;
    }
    else if(T->rbit==1)
    {
        T=T->right;
    }
    else{
        while(T->rbit!=1)
        {
            T=T->right;
        }
        T=T->right;
    }
    return T;
}
void TBT:: preorder()
{
    Node*Temp;
    Temp=root->left;
    while(Temp!=root)
    {
        cout<<Temp->data<< " ";
        Temp=preorder_succ(Temp);
    }
}
Node* TBT::inorder_succ(Node*T)
{
    if(T->rbit==0)
    {
        T=T->right;
    }
    else{
        T=T->right;
        while(T->lbit==1)
        {
            T=T->left;
        }
    }
    return T;
}
void TBT::inorder()
{
    Node*Temp=root->left;
    while(Temp->lbit==1)
    {
        Temp=Temp->left;
    }
    while(Temp!=root)
    {
        cout<<Temp->data<<" ";
        Temp=inorder_succ(Temp);
    }
}
Node* TBT::postorder_succ(Node*T)
{
    if(T->child==1)
    {
        while(T->rbit==1)
        {
            T=T->left;
        }
        T=T->left;
        return T;
    }
    return T;
}
void TBT::postorder()
{
    Node*T=root->left;
    while(T->lbit!=0 || T->rbit!=0)
    {
        if(T->lbit==1)
        {
            T=T->left;
        }
        else{
            T=T->right;
        }
    }
    while (T!=root)
    {
        cout<<T->data;
        T=postorder_succ(T);
    }
    
}
int main()
{
    TBT tbt;
    tbt.create();
    cout<<"inorder= ";
    tbt.inorder(tbt.getroot()->left);
    cout<<endl<<"preorder= ";
    tbt.preorder();
    cout<<endl<<"inorder= ";
    tbt.inorder();
}