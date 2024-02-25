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
void BT::inorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    inorder(T->left);
    cout<<T->data;
    inorder(T->right);
}
void BT::postorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    postorder(T->left);
    postorder(T->right);
    cout<<T->data;
}
void BT::preorder()
{
    Node*T=root;
    stack<Node*>stk;
    while(T!=NULL)
    {
        stk.push(T);
        cout<<T->data;
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.top();
        stk.pop();
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            cout<<T->data;
            T=T->left;
        }
    }
}
void BT::inorder()
{
    Node*T=root;
    stack<Node*>stk;
    while(T!=NULL)
    {
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.top();
        stk.pop();
        cout<<T->data;
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            T=T->left;
        }
    }
}
void BT::postorder()
{
    Node*T=root;
    stack<StackNode>stk;
    StackNode sn;
    while(T!=NULL)
    {
        sn.add=T;
        stk.push(sn);
        T=T->left;
    }
    while(!stk.empty())
    {
        sn=stk.top();
        stk.pop();
        T=sn.add;
        if(sn.flag==1)
        {
            cout<<T->data;
        }
        else
        {
            sn.flag++;
            stk.push(sn);
            T=T->right;
            while(T!=NULL)
            {
                sn.add=T;
                sn.flag=0;
                stk.push(sn);
                T=T->left;
            }
        }
    }
}
bool BT::search(Node*T,int x)
{
    if(T==NULL)
    {
        return false;
    }
    if(T->data==x)
    {
        return true;
    }
    int l=0;
    l=search(T->left,x);
    if(l==1)
    {
        return 1;
    }
    else{
        return search(T->right,x);
    }
}
int BT::count(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL){
        return 1;
    }
    if(T->left==NULL)
    {
        return 1+count(T->right);
    }
    if(T->right==NULL)
    {
        return 1+count(T->left);
    }
    return count(T->left) +count(T->right)+1;
}
int BT::count0(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 1;
    }
    return count0(T->left)+count0(T->right);
}
int BT:: count1(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 0;
    }
    if(T->left==NULL)
    {
        return 1+count1(T->right);
    }
    if(T->right==NULL)
    {
        return 1+count1(T->left);
    }
    return count1(T->left)+count1(T->right);
}
int BT::count2(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 0;
    }
    if(T->left==NULL)
    {
        return count2(T->right);
    }
    if(T->right==NULL)
    {
        return count2(T->left);
    }
    return count2(T->left)+count2(T->right)+1;
}
int main()
{
    BT b1;
    b1.crt();
    cout<<"\npre= ";
    b1.preorder(b1.getroot());
    cout<<"\nin";
    b1.inorder(b1.getroot());
    cout<<"\npost";
    b1.postorder(b1.getroot());
    cout<<"\npre";
    b1.preorder();
    cout<<"\nin";
    b1.inorder();
    cout<<"post\n";
    b1.postorder();
    cout<<endl<<b1.search(b1.getroot(),4);
    cout<<endl<<b1.count(b1.getroot());
    cout<<endl<<b1.count0(b1.getroot());
    cout<<endl<<b1.count1(b1.getroot());
    cout<<endl<<b1.count2(b1.getroot());
    cout<<endl<<b1.height(b1.getroot());
}