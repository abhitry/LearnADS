#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int d;
    Node*next;
    Node()
    {
        d=0;
        next=NULL;
    }
    Node(int a)
    {
        d=a;
        next=NULL;
    }
};
class TreeNode
{
    public:
    int data;
    TreeNode*left,*right;
    Node*head;
    TreeNode()
    {
        data=0;
        left=right=NULL;
        head=NULL;
    }
    TreeNode(int a)
    {
        data=a;
        left=right=NULL;
        head=NULL;
    }
};
class SLL
{
    Node*head;
    public:
    SLL()
    {
        head=NULL;
    }
    void addatend(int x)
    {
        if(head==NULL)
        {
            head=new Node(x);
        }
        else{
            Node*p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=new Node(x);
        }
    }
    void create(int num)
    {
        int i;
        for(i=2;i<=num;i++)
        {
            while(num%i==0)
            {
                addatend(i);
                num=num/i;
            }
        }
        addatend(1);
    }
    Node*gethead()
    {
        return head;
    }

};
void makeempty(Node*p)
{
    Node*q;
    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
}
void show(Node*T)
{   
    while(T!=NULL)
    {
        cout<<T->d<<" ";
        T=T->next;
    }
}
class BST
{
    TreeNode*root;
    public:
    BST()
    {
        root=NULL;
    }
    void insert(int x);
    void create()
    {
        int x;
        while(1)
        {
            cout<<"enter numbers= ";
            cin>>x;
            if(x==0)
            {
                break;
            }
            insert(x);
        }
    }
    void inorder(TreeNode*);
    TreeNode*getroot()
    {
        return root;
    }
    int search(TreeNode*,int x);
    void deleten();
    TreeNode* deletenode (TreeNode*T,int x);
};
void BST::insert(int x)
{
    TreeNode*T=root;
    TreeNode*p=NULL;
    if(root==NULL)
    {
        root=new TreeNode(x);
        SLL s;
        s.create(x);
        root->head=s.gethead();
        return ;
    }
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
        else{
            cout<<"duplicate";
            return;
        }
    }
    if(x<p->data)
    {
        p->left=new TreeNode(x);
        SLL s;
        s.create(x);
        p->left->head=s.gethead();
    }
    else{
        p->right=new TreeNode(x);
        SLL s;
        s.create(x);
        p->right->head=s.gethead();
    }
}
void BST::inorder(TreeNode*T)
{
    if(T==NULL)
    {
        return ;
    }
    cout<<T->data<<"        ";
    show(T->head);
    cout<<endl;
    inorder(T->left);
    inorder(T->right);
}
int BST::search(TreeNode*T,int x)
{
    if(T==NULL)
    {
        return 0;
    }
    if(x==T->data)
    {
        show(T->head);
        return 1;
    }
    int res;
    if(x<T->data)
    {
        res=search(T->left,x);
        return res;
    }
    else if(x>T->data)
    {
        res=search(T->right,x);
        return res;
    }
    return 0;
}
void BST::deleten()
{
    int x;
    cout<<"enter number to delteed= ";
    root=deletenode(root,x);
}
TreeNode*findmin(TreeNode*T)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(T->left==NULL)
    {
        return T;
    }
    return findmin(T->left);
}
TreeNode* BST::deletenode (TreeNode*T,int x)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(x<T->data)
    {
        T->left=deletenode(T->left,x);
        return T;
    }
    if(x>T->data)
    {
        T->right=deletenode(T->right,x);
        return T;
    }
    if(T->left==NULL && T->right==NULL)
    {
        delete T;
        makeempty(T->head);
        return NULL;
    }
    if(T->left==NULL)
    {
        TreeNode*p=T->right;
        makeempty(T->head);
        delete T;
        return p;
    }
    if(T->right==NULL)
    {
        TreeNode*p=T->left;
        makeempty(T->head);
        delete T;
        return p;
    }
    TreeNode*p=findmin(T->right);
    T->data=p->data;
    SLL s;
    s.create(p->data);
    T->head=s.gethead();
    T->right=deletenode(T->right,p->data);
    return T;
};
int main()
{
    BST bst;
    bst.create();
    bst.inorder(bst.getroot());
    cout<<"search in bst = \n";
    bst.search(bst.getroot(),35);
    cout<<endl;
    bst.deletenode(bst.getroot(),35);
    bst.inorder(bst.getroot());
}