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
class BinaryTree
{
    Node*root;
    public:
    BinaryTree()
    {
        root=NULL;
    }
    void create();
};
void BinaryTree::create()
{
    int x;
    cout<<"enter data= ";    
    while(1)
    {
        cin>>x;
        if(x==0)
        {
            break;
        }        
    }
    
}
int main()
{

}