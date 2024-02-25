#include<iostream>
using namespace std;
class TBTNode
{
    public:
    int lbit,rbit;
    TBTNode*left,*right;
    int data;
    int child;
    TBTNode()
    {
        lbit=rbit=0;
        left=right=NULL;
        data=0;
        child=-1;
    }
    TBTNode(int a)
    {
        lbit=rbit=0;
        left=right=NULL;
        data=a;
        child=-1;
    }
};
class TBT
{
    TBTNode*root;
    public:
    TBT()
    {
        root=new TBTNode(-1);
        root->left=root->right=root;
        root->lbit=root->rbit=1;
    }
    void create();
    void create_rec(TBTNode*father,int child);
    void preorder();
    TBTNode* pre_succ(TBTNode*);
    void inorder();
    TBTNode*in_succ(TBTNode*);
    void postorder();
    TBTNode*post_succ(TBTNode*);
};
void TBT::create()
{
    create_rec(root,0);
}
void TBT::create_rec(TBTNode*father,int child)
{
    int x;
    cout<<"enter data=";
    cin>>x;
    if(x==0)
    {
        return;
    }
    TBTNode*T=new TBTNode(x);
    if(child==0)
    {
        T->left=father->left;
        T->right=father;
        T->child=0;
        father->left=T;
        father->lbit=1;
    }
    if(child==1)
    {
        T->right=father->right;
        T->left=father;
        T->child=1;
        father->right=T;
        father->rbit=1;
    }
    create_rec(T,0);
    create_rec(T,1);
}
void TBT ::preorder()
{
    TBTNode*Temp=root->left;
    while(Temp!=root)
    {
        cout<<Temp->data;
        Temp=pre_succ(Temp);
    }
}
TBTNode*TBT::pre_succ(TBTNode*T)
{
    if(T->lbit==1)
    {
        return T->left;
    }
    else{
        while(T->rbit==0)
        {
            T=T->right;
        }
        T=T->right;
        return T;
    }
}
void TBT::inorder()
{
    TBTNode*Temp=root->left;
    while(Temp->lbit==1)
    {
        Temp=Temp->left;
    }
    while(Temp!=root)
    {
        cout<<Temp->data;
        Temp=in_succ(Temp);
    }
}
TBTNode* TBT::in_succ(TBTNode*T)
{
    if(T->rbit==0)
    {
        T=T->right;
    }
    else
    {
        T=T->right;
        while(T->lbit==1)
        {
            T=T->left;
        }

    }
    return T;
}
void TBT::postorder()
{
    TBTNode*Temp=root->left;
    while(Temp->lbit!=0 && Temp->rbit!=0)
    {
        if(Temp->lbit==1)
        {
            Temp=Temp->left;
        }
        else if(Temp->rbit==1)
        {
            Temp=Temp->right;
        }
    }
    while(Temp!=root)
    {
        cout<<Temp->data;
        Temp=post_succ(Temp);
    }
}
TBTNode* TBT::post_succ(TBTNode*T)
{
    if(T->child==1)
    {
        while(T->lbit==1)
        {
            T=T->left;
        }
        T=T->left;
        return T;
    }
    while(T->rbit==1)
    {
        T=T->right;
    }
    T=T->right;
    if(T->rbit==0 || T==root)
    {
        return T;
    }
    T=T->right;
    while(T->lbit!=0 && T->rbit!=0)
    {
        if(T->lbit==1)
        {
            T=T->left;
        }
        if(T->rbit==1)
        {
            T=T->right;
        }
        return T;
    }
    return T;
}
int main()
{
    TBT T1;
    T1.create();
    T1.preorder();
    cout<<endl;
    T1.inorder();
    cout<<endl;
    T1.postorder();
}