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
class StackNode
{
    public:
    Node*add;
    int flag;
    StackNode()
    {
        add=NULL;
        flag=0;
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
    void crt();
    Node* create();
    void preorder(Node*T);
    void inorder(Node*);
    void postorder(Node*);
    Node*getroot()
    {
        return root;
    }
    void preorder();
    void inorder();
    void postorder();
    bool search(Node*T,int x);
    int count(Node*);
    int count1(Node*);
    int count2(Node*);
    int count0(Node*);
    int height(Node*T)
    {
        if(T==NULL)
        {
            return 0;
        }
        return max(height(T->left),height(T->right))+1;
    }
    void copy(Node*T);
    Node*copy_rec(Node*p);

};
void BT::crt()
{
    root=create();
}
Node* BT::create()
{
    int x;
    cout<<"enter data=";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*T=new Node(x);
    T->left=create();
    T->right=create();
    return T;
}
void BT::preorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    cout<<T->data;
    preorder(T->left);
    preorder(T->right);
}
void BT::copy(Node*T)
{
    root->left=copy_rec(T);
}
Node*BT::copy_rec(Node*p)
{
    if(p==NULL)
    {
        return NULL;
    }
    Node*T=new Node(p->data);
    T->left=copy_rec(p->left);
    T->right=copy_rec(p->right);
    return T;
}
int main()
{
    BT b1;
    b1.crt();
    BT b2;
    b2.copy(b1.getroot());
    b2.preorder();
}