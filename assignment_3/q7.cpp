#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    char cityname[30];
    Node*left,*right;
    Node()
    {
        cityname[0]='\0';
        left=right=NULL;
    }
    Node(char a[30])
    {
        strcpy(cityname,a);
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
    void insert_nonrec(char *p);
    Node*getroot()
    {
        return root;
    }
    int search(Node*,char ch[]);
    int count(Node*T);
    void delete_city();

};
void BST::insert_nonrec(char ch[])
{
    if(root==NULL)
    {
        root=new Node(ch);
        return;
    }
    Node*T=root;
    Node*p=NULL;
    while(T!=NULL)
    {
        p=T;
        if(strcmp(ch,T->cityname)<0)
        {
            T=T->left;
        }
        else if(strcmp(ch,T->cityname)>0)
        {
            T=T->right;
        }
        else{
            cout<<"duplicate";
            return;
        }
    }
    if(strcmp(ch,p->cityname)<0)
    {
        p->left=new Node(ch);
    }
    else{
        p->right=new Node(ch);
    }
}
void BST::create()
{
    char xh[30];
    cout<<"ernter cityname=";
    while(1)
    {
        cin.getline(xh,29);
        if(strcmp(xh,"STOP")==0)
        {
            return ;
        }
        insert_nonrec(xh);
    }
}
void inorder(Node*T)
{
    if(T==NULL)
    {
        return;
    }
    inorder(T->left);
    cout<<T->cityname<<" ";
    inorder(T->right);
}
int BST:: search(Node*T,char ch[])
{
    if(T==NULL)
    {
        return 0;
    }
    if(strcmp(T->cityname,ch)==0)
    {

        return 1;
    }
    int res;
    res=search(T->left,ch);
    if(res==0)
    {
        res=search(T->right,ch);
    }
    return res;
}
int BST::count(Node*T)
{
    if(T==NULL)
    {
        return 0;
    }
    int cl,cr;
    cl=count(T->left);
    cr=count(T->right);
    return 1+cl+cr;
}

Node* findmin(Node*T)
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
Node*delete_cityr(Node*T,char ch[])
{
    if(T==NULL)
    {
        return NULL;
    }
    if(strcmp(ch,T->cityname)<0)
    {
        T->left=delete_cityr(T->left,ch);
        return T;
    }
    else if(strcmp(ch,T->cityname)>0)
    {
        T->right=delete_cityr(T->right,ch);
        return T;
    }
    if(T->left==NULL && T->right==NULL)
    {
        delete T;
        return NULL;
    }
    if(T->left==NULL)
    {
        Node*p=T->right;
        delete T;
        return p;
    }
    else if(T->right==NULL)
    {
        Node*p=T->left;
        delete T;
        return p;
    }
    Node*p=findmin(T->right);
    strcpy(T->cityname,p->cityname);
    T->right=delete_cityr(T->right,p->cityname);
    return p;
}
void BST::delete_city()
{
    char x[30];
    cout<<"enter city to be deleted=";
    cin.getline(x,30);
    root=delete_cityr(root,x);
}
int main()
{
    BST t1;
    t1.create();
    inorder(t1.getroot());
    char x[30]="pune";
    cout<<"seacrh="<<endl<<t1.search(t1.getroot(),x);
    cout<<endl<<"count="<< t1.count(t1.getroot());
    t1.delete_city();
    inorder(t1.getroot());
}