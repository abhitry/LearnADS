#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node*left,*right;
    Node()
    {
        left=right=NULL;
        data=0;
    }
    Node(int a)
    {
        left=right=NULL;
        data=a;
    }
};
Node* rec_create()
{
    cout<<"enter dtata=";
    int x;
    cin>>x;
    if(x==0)
    {
        return NULL;
    }
    Node*p=new Node(x);
    cout<<"enter left node=";
    p->left=rec_create();
    cout<<"enter right node=";
    p->right=rec_create();
return p;
}
class Tree
{
    Node*root;
    public:
    Tree()
    {
        root=NULL;
    }
    void create()
    {
        root=rec_create();
    }
};

int main()
{
    Tree T1;
    T1.create();
}