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
    Node* add;
    int flag;
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
    int search_rec(int x);
    int search_nonrec(int x);
    void postorder_nonrec();
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
void BinaryTree::create()
{
    root=creat();
}
void preorder_rec(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    cout<<T->data;
    preorder_rec(T->left);
    preorder_rec(T->right);
}
void inorder_rec(Node*T)
{
    if(T==NULL)
    {
        return ;
    }
    inorder_rec(T->left);
    cout<<T->data;
    inorder_rec(T->right);
}
void postorder_rec(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    postorder_rec(T->left);
    postorder_rec(T->right);
    cout<<T->data;
}
void BinaryTree::postorder_nonrec()
{
    Node*T=root;
    StackNode sn;
    stack<StackNode>stk;
    while(T!=NULL)
    {
        sn.add=T;
        sn.flag=0;
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
        else{
            sn.flag=1;
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
int count(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    int cl,cr;
    cl=count(T->left);
    cr=count(T->right);
    return cl+cr+1;
}
int count0(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 1;
    }
    int cl,cr;
    cl=count0(T->left);
    cr=count0(T->right);
    return cl+cr;
}
int count1(Node*T)
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
    return 0+count1(T->left)+count1(T->right);
}
int count2(Node*T)
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
        return 0+count2(T->right);
    }
    if(T->right==NULL)
    {
        return 0+count2(T->left);
    }
    return 1+count2(T->left)+count2(T->right);
}
int height(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
    {
        return 0;
    }
    int h1=0,h2=0;
    if(T->left!=NULL)
    {
        h1= 1+height(T->left);
    }
    if(T->right!=NULL)
    {
        h2= 1+height(T->right);
    }
    if(h1>h2)
    {
        return h1;
    }
    return h2;
}
int main()
{
    BinaryTree bt;
    bt.create();
    cout<<endl<<"height="<<height(bt.getroot())<<endl;
    preorder_rec(bt.getroot());
    cout<<endl;
    inorder_rec(bt.getroot());
    cout<<endl;
    postorder_rec(bt.getroot());
    cout<<endl;
    bt.postorder_nonrec();
    cout<<endl<<"\nall count : "<<count(bt.getroot());
    cout<<endl<<"\nzero degree count : "<<count0(bt.getroot());
    cout<<endl<<"\none degree count : "<<count1(bt.getroot());
    cout<<endl<<"\ntwo degree count : "<<count2(bt.getroot());
    cout<<endl<<height(bt.getroot());

}