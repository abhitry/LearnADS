#include<iostream>
using namespace std;
class Node
{
    public:
    char ch;
    Node*next;
    Node()
    {
        ch='\0';
        next=NULL;
    }
    Node(char c)
    {
        ch=c;
        next=NULL;
    }
};
class WordNode
{
    public:
    string  word;
    WordNode*next;
    Node*head;
    WordNode()
    {
        next=NULL;
        head=NULL;
    }
    WordNode(string ch)
    {
        word=ch;
        next=NULL;
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
    void create(char arr[30])
    {
        Node*p=new Node(arr[0]);
        head=p;
        int i=1;
        while(arr[i]!='\0')
        {
            p->next=new Node(arr[i]);
            p=p->next;
            i++;
        }
    }
    Node*getroot()
    {
        return  head;
    }
}; 
Node*link(string num)
{
    char ch[30];
    int i=0,j=0,k=0;
    sort(num.begin(),num.end());
    for(int i=0;i<num.length();i++)
    {   
        j=i+1;
        if(num[i]!=num[j])
        {
            ch[k]=num[i];
            k++;
        }
    }
    ch[k]='\0';
    SLL q;
    q.create(ch);
    return q.getroot();
}
class WordSLL
{   
    WordNode*head;
    public:
    WordSLL()
    {
        head=NULL;
    }
    void create()
    {
        string num;
        cout<<"enter word or enter STOP to stop= ";
        getline(cin,num);
        WordNode*p=new WordNode(num);
        head=p;
        p->head=link(num);
        while(1)
        {
            cout<<"enter name=";
            getline(cin,num);
            if(num=="STOP")
            {
                break;
            }
            p->next=new WordNode(num);
            p->next->head=link(num);
            p=p->next;
        }
    }
    void print()
    {
        WordNode*p=head;
        while(p!=NULL)
        {
            cout<<p->word<<" ";
             Node*q=p->head;
            while(q!=NULL)
            {
                cout<<q->ch;
                q=q->next;
            }
            cout<<endl;
            p=p->next;
        }
        cout<<endl;
    }
};
int main()
{
    WordSLL S1;
    S1.create();
    cout<<endl;
    S1.print();
}