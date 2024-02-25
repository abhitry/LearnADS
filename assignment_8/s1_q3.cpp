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
    Node(int a){
        data=a;
        left=right=NULL;
    }
};

Node*createfrominorder(int preorder[],int &i,int ub)
{
    Node*p=NULL;
    if(preorder[i]==-1 || preorder[i]>ub)
    {
        return NULL;
    }
    p=new Node(preorder[i]);
    i++;
    p->left=createfrominorder(preorder,i,p->data);
    p->right=createfrominorder(preorder,i,ub);
    return p;
}
void inord(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    inord(T->left);
    cout<<T->data<<" ";
    inord(T->right);
}
int main()
{
    int preorder[10];
    int inorder[10];
    int i;
    cout<<"enter preorder= ";
    for( i=0;i<10;i++)
    {
         cin>>preorder[i];
        if(preorder[i]==-1)
        {
            break;
        } 
    }
    cout<<"enter inorder= ";
    for( i=0;i<10;i++)
    {
        cin>>inorder[i];
         if(preorder[i]==-1)
        {
            break;
        }
    }
    i=0;
    Node*root=createfrominorder(preorder,i,INT_MAX);
    cout<<endl;
    inord(root);
}