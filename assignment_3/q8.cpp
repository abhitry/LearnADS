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
class BT
{
    Node*root;
    public:
    BT()
    {
        root=NULL;
    }
    void create();
    int findmin(Node*T);
    Node*getroot()
    {
        return root;
    }
    int findmax(Node*T);

};

Node* create_rec()
{   
    int x;
    cout<<"\nenter data=";
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*p=new Node(x);
    cout<<"enter left data: ";
    p->left=create_rec();
    cout<<"enetr right data: ";
    p->right=create_rec();
return p;
}
void BT::create()
{
    root=create_rec();
}
int BT::findmin(Node*T)
{
    if(T==NULL)
    {
        return INT_MAX;
    }
    int value,c1,c2;
    value=T->data;
    c1=findmin(T->left);
    c2=findmin(T->right);
    return min(value,min(c1,c2));
}





int BT::findmax(Node*T)
{
    if(T==NULL)
    {
        return INT_MIN;
    }
    int value,c1,c2;
    value=T->data;
    c1=findmax(T->left);
    c2=findmax(T->right);
    return max(value,max(c1,c2));
}
int main()
{
    BT bt;
    bt.create();
    cout<<bt.findmin(bt.getroot());
    cout<<bt.findmax(bt.getroot());
}
