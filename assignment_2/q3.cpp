#define MAX 20
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
class Stack
{
    Node* data[MAX];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    int empty()
    {
        if(top==-1)
        {
            return 1;
        }
        return 0;
    }
    int full()
    {
        if(top==MAX-1)
        {
            return 1;
        }
        return 0;
    }
    void push(Node* T)
    {
        if(!full())
        {
            top++;
            data[top]=T;
        }
        else{
            cout<<"full";
        }
    }
    Node* pop()
    {
        Node*x;
        if(!empty())
        {
            x=data[top];
            top--;
        }
        else{
            cout<<"empty";
        }
        return x;
    }
};


class Tree
{
    Node*root;
    public:
    Tree()
    {
        root=NULL;
    }
    void create();
    Node* getroot()
    {
        return root;
    }
    int search(int x);
    Node*  rec_create();
};
int Tree::search(int x)
{
    Stack stk;
    Node* T=root;
    while(T!=NULL)
    {
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.pop();
        if(T->data==x)
        {
            return 1;
        }
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            T=T->left;
        }
    }
    return 0;
}
// int rec_search(Node*T,int x)
// {
//     if(T==NULL)
//     {
//         return 0;
//     }
//     if(T->data==x)
//     {
//         return 1;
//     }
//     int res;
//     res=rec_search(T->left,x);
//     if(res==0)
//     {
//         res=rec_search(T->right,x);
//     }
//     return res;
// }
Node* Tree:: rec_create()
{
    int x;
    cout<<"\nenter data=";
    cin>>x;
    if(x<=0)
    {
        return NULL;
    }
    if(search(x))
    {
        return NULL;
    }
    Node*T=new Node(x);
    cout<<"enter left data:";
    T->left=rec_create();
    cout<<"enter right data:";
    T->right=rec_create();
    return T;
    
}
void Tree::create()
{
    root=rec_create();
}
void preorder_rec(Node*T)
{
    if(T==NULL)
    {
        return ;
    }
    cout<<T->data;
    preorder_rec(T->left);
    preorder_rec(T->right);
}

int main()
{
    Tree T1;
    T1.create();
    Node*r=T1.getroot();
    preorder_rec(r);
    cout<<endl;
    cout<<T1.search(3);
}