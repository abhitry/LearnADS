#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*left;
    Node*right;
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
Node* rec_create()
{
    int x;
    cout<<"\nentre data=";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*T=new Node(x);
    cout<<"enter left data:";
    T->left=rec_create();
    cout<<"enert right data:";
    T->right=rec_create();
return T;
}
class Tree
{
    Node*root;
    public:
    Tree()
    {
        root=NULL;
    }
    Node* gethead()
    {
        return root;
    }
    void create()
    {
        root=rec_create();
    }
};

void preorder_rec(Node* T)
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
int search_rec(Node*T,int x)
{
    if(T==NULL)
    {
        return 0;
    }
    if(T->data==x)
    {
        return 1;
    }
    int res;
    res=search_rec(T->left,x);
    if(res==0)
    {
        res=search_rec(T->right,x);
    }
    return res;
}
int count_rec(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    int cl,cr;
    cl=count_rec(T->left);
    cr=count_rec(T->right);
    return cl+cr+1;
}
int main()
{
    Tree T1;
    T1.create();
    Node*r=T1.gethead();
    preorder_rec(r);
    cout<<endl;
    inorder_rec(r);
    cout<<endl;
    postorder_rec(r);
    cout<<endl;
    if(search_rec(r,5))
    {
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    cout<<count_rec(r);
}