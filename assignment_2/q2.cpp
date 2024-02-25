
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
    void push(Node*T)
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
            cout<<"empoty";
        }
        return x;
        
    }
};
class Stacknode
{
    public:
    Node *address;
    int flag;
};

class Stackn
{
    Stacknode data[MAX];
    int top;
    public:
    Stackn()
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
    void push(Stacknode T)
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
    Stacknode pop()
    {
        Stacknode x;
        if(!empty())
        {
            x=data[top];
            top--;
        }
        else{
            cout<<"empoty";
        }
        return x;
        
    }
};
Node*rec_create()
{
    int x;
    cout<<"\nenetr data=";
    cin>>x;
    if(x==0)
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
class Tree
{
    public:
    Node*root;
    Tree()
    {
        root=NULL;
    }
    void create()
    {
        root=rec_create();
    }
    Node*getroot()
    {
        return root;
    }
    void preorder_nonrec();
    void inorder_nonrec();
    void postorder_nonrec();
    int search_nonrec(int x);
    int count_nonrec();

};
void inorder_rec(Node*T)
{
    if(T==NULL){
        return  ;
    }
    inorder_rec(T->left);
    cout<<T->data;
    inorder_rec(T->right);
}
void Tree::preorder_nonrec()
{
    Node*T=root;
    Stack stk;
    while(T!=NULL)
    {
        cout<<T->data;
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.pop();
        T=T->right;
        while(T!=NULL)
        {
            cout<<T->data;
            stk.push(T);
            T=T->left;
        }
    }
}
void Tree::inorder_nonrec()
{
    Stack stk;
    Node*T=root;
    while(T!=NULL)
    {
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.pop();
        cout<<T->data;
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            T=T->left;
        }
    }
}
void Tree::postorder_nonrec()
{
    Stackn stk;
    Node*T=root;
    Stacknode sn;
    while(T!=NULL)
    {
        sn.address=T;
        sn.flag=0;
        stk.push(sn);
        T=T->left;
    }
    while(!stk.empty())
    {
        sn=stk.pop();
        T=sn.address;
        if(sn.flag==1)
        {
            cout<<T->data;
        }
        else
        {
            sn.flag=1;
            stk.push(sn);
            T=T->right;
            while(T!=NULL)
            {
                sn.address=T;
                sn.flag=0;
                stk.push(sn);
                T=T->left;
            }
        }
    }
}
int Tree::search_nonrec(int x)
{
    Stack stk;
    Node*T=root;
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
int Tree::count_nonrec()
{
    Stack stk;
    Node*T=root;
    int count=0;
    while(T!=NULL)
    {
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        T=stk.pop();
        count++;
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            T=T->left;
        }
    }
    return count;
}
int main()
{
    Tree T1;
    T1.create();
    Node*r=T1.getroot();
    inorder_rec(r);
    cout<<endl;
    T1.preorder_nonrec();
    cout<<endl;
    T1.inorder_nonrec();
    cout<<endl;
    T1.postorder_nonrec();
    cout<<endl;
    cout<<T1.search_nonrec(15);
    cout<<endl;
    cout<<T1.count_nonrec();
    cout<<endl;
}
