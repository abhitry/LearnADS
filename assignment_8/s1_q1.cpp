#include<iostream>
using namespace std;
class Node
{
    public:
    int vertex;
    Node*next;
    Node()
    {
        vertex=0;
        next=NULL;
    }
    Node(int a)
    {
        vertex=a;
        next=NULL;
    }
};
class Graph
{
    Node* head[10];
    public:
    int n;
    bool dir;
    int wt;
    int start;
    Graph()
    {
        n=0;
        for(int i=0;i<10;i++){
            head[i]=NULL;
        }
    }
    void create_graph();
    void read_graph_edges();
    void insert_edge(int,int);
    void outdegree();
    void inorder();
};
void Graph::create_graph()
{
    cout<<"enter number of vertices= ";
    cin>>n;
    cout<<"is it directed= ";
    cin>>dir;
    cout<<"is it weighted= ";
    cin>>wt;
    cout<<"give start vertex= ";
    cin>>start;   
}
void Graph::insert_edge(int u,int v)
{
    if(head[u]==NULL)
    {
        head[u]=new Node(v);
    }
    else{
        Node*p=head[u];
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=new Node(v);
    }
}
void Graph::read_graph_edges()
{
    cout<<"enter edges= ";
    int u,v;
    while(1)
    {
        cin>>u>>v;
        if(u==-1 || v==-1)
        {
            break;
        }
        insert_edge(u,v);
        if(dir==0){
            insert_edge(v,u);
        }
    }
}
void Graph::outdegree()
{
    int i=0;
    int count=0;
    Node*p;
    for(i=0;i<n;i++){
        p=head[i];
        count=0;
        while(p!=NULL)
        {
            p=p->next;
            count++;
        }
        cout<<"outdegree is = "<<count<<endl;
    }
    cout<<endl;
}
void Graph::inorder()
{
    int i;
    for(i=0;i<n;i++)
    {
        int count=0;
        Node*p;
        for(int j=0;j<n;j++)
        {
            p=head[j];
            while(p!=NULL)
            {
                if(p->vertex == i)
                {
                    count++;
                }
                p=p->next;
            }
        }
        cout<<"indegree is = "<<count;
    }
}
int main()
{
    Graph g;
    g.create_graph();
    g.read_graph_edges();
    g.outdegree();
    g.inorder();
}