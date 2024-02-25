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
class BST
{
    Node*root;
    public:
    BST()
    {
        root=NULL;
    }
    void create();
    void insert_nonrec(int x);
    void preorder_rec();
    void inorder_rec();
    void postorder_rec();
    Node*findmin_nonrec();
    Node*findmax_nonrec();
    int search_nonrec(int x);
    Node* getroot()
    {
        return root;
    }
    void deletenode();
};

void BST::insert_nonrec(int x)
{
    if(root==NULL)
    {
        root=new Node(x);
        return;
    }
    Node*T=root;
    Node*p=NULL;
    while(T!=NULL)
    {
        p=T;
        if(x<T->data)
        {
            T=T->left;
        }
        else if(x>T->data)
        {
            T=T->right;
        }
        else
        {
            cout<<"duplicate";
            return;
        }
    }
    if(x<p->data)
    {
        p->left=new Node(x);
    }
    else{
        p->right=new Node(x);
    }
}
Node* insert_rec(Node*T,int x)
{
    if(T==NULL)
    {
        T=new Node(x);
        return T;
    } 
    if(x<T->data)
    {
        T->left=insert_rec(T->left,x);
        return T;
    }
    else if(x>T->data)
    {
        T->right=insert_rec(T->right,x);
        return T;
    }
    else{
        cout<<"duplicate";
    }
    return T;
}
void BST::create()
{
    int x;
    cout<<"enter input=";
    while(1)
    {
        cin>>x;
        if(x==0)
        {
            break;
        }
        root=insert_rec(root,x);
    }
}
void inorder_rec(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    inorder_rec(T->left);
    cout<<T->data;
    inorder_rec(T->right);
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
Node*findmin_rec(Node* T)
{
    if(T==NULL)
    {
        return  NULL;
    }
    if(T->left==NULL)
    {
        return T;
    }
    return findmin_rec(T->left);
}
Node*findmax_rec(Node* T)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(T->right==NULL)
    {
        return T;
    }
    return findmax_rec(T->right);
}
Node* BST::findmin_nonrec()
{
    Node*T=root;
    if(T==NULL)
    {
        return NULL;
    }
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;

}
Node*BST::findmax_nonrec()
{
    Node*T=root;
    if(T==NULL)
    {
        return NULL;
    }
    while(T->right!=NULL)
    {
        T=T->right;
    }
    return T;
}
int BST::search_nonrec(int x)
{
    Node*T=root;
    if(T==NULL){
        return 0;
    }
    while(T!=NULL)
    {
        if(x==T->data)
        {
            return 1;
        }
        else if(x<T->data)
        {
            T=T->left;
        }
        else
        {
            T=T->right;
        }
    }
    return 0;
}
int search_rec(Node*T,int x)
{
    if(T==NULL)
    {
        return 0;
    }
    else if(T->data==x)
    {
        return 1;
    }
    else if(x<T->data)
    {
        return search_rec(T->left,x);
    }
    else 
    {
        return search_rec(T->right,x);
    }
}

Node* delete_Node(Node*T,int x)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(x<T->data)
    {
        T->left=delete_Node(T->left,x);
        return T;
    }
    else if(x>T->data)
    {
        T->right-delete_Node(T->right,x);
        return T;
    }
    if(T->left==NULL && T->right==NULL)
    {
        delete T;
        return NULL;
    }
    else if(T->right==NULL)
    {
        Node*p=T->left;
        delete T;
        return p;
    }
    else if(T->left==NULL)
    {
        Node*p=T->right;
        delete T;
        return p;
    }
    Node*p=findmin_rec(T->right);
    T->data=p->data;
    T->right=delete_Node(T->right,p->data);
    return T;
}
void BST::deletenode()
{
    int x;
    cout<<"enter node to be deleted = ";
    cin>>x;
    root=delete_Node(root,x);
}
int main()
{
    BST T1;
    T1.create();
    inorder_rec(T1.getroot());
    Node*p;
    p=findmin_rec(T1.getroot());
    cout<<endl<<p->data;
    p=findmax_rec(T1.getroot());
    cout<<endl<<p->data;
    p=T1.findmin_nonrec();
    cout<<endl<<p->data;
    p=T1.findmax_nonrec();
    cout<<endl<<p->data;
    cout<<endl<<T1.search_nonrec(5);
    cout<<endl<<search_rec(T1.getroot(),5);
    T1.deletenode();
    inorder_rec(T1.getroot());
    T1.deletenode();
    inorder_rec(T1.getroot());    
    T1.deletenode();
    inorder_rec(T1.getroot());    
    T1.deletenode();
    inorder_rec(T1.getroot());
}