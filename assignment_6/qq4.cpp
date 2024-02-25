#include<iostream>
#include<stack>
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
    Node(int v)
    {
        vertex=v;
        next=NULL;
    }
};
class Graph
{
    Node*head[10];
    public:
    int n;
    bool dir,wt;
    int start;
    Graph()
    {
        n=0;
        for(int i=0;i<10;i++)
        {
            head[i]=NULL;
        }
    }
    void create_graph()
    {
        cout<<"enter vertices= ";
        cin>>n;
        cout<<"enter dir= ";
        cin>>dir;
        cout<<"enter wt= ";
        cin>>wt;
        cout<<"enter start= ";
        cin>>start;
    }
    void insert_edge(int u,int v)
    {
        Node*p=head[u];
        if(head[u]==NULL)
        {
            head[u]=new Node(v);
        }
        else{
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=new Node(v);
        }
    }
    void read_graph_edge()
    {
        int u,v;
        cout<<"(u,v) or (v,u)";
        while(1)
        {
            cin>>u>>v;
            if(u==-1 ||v==-1)
            {
                break;
            }
            insert_edge(u,v);
            if(dir==0)
            {
                insert_edge(v,u);
            }
        }
    }
    void print_graph()
    {
        Node*p;
        for(int i=0;i<n;i++)
        {
            p=head[i];
            while(p!=NULL)
            {
                cout<<p->vertex;
                p=p->next;
            }
            cout<<endl;
        }
    }
   void DFS_nonrec(int* visited, int vertex) {
        stack<int> stk;
        stk.push(vertex);
        visited[vertex] = 1;

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();
            cout << u << "visited "<<endl;  // Print the visited vertex

            Node* p = head[u];
            while (p != NULL) {
                if (visited[p->vertex]==0) {
                    stk.push(p->vertex);
                    visited[p->vertex] = 1;
                }
                p = p->next;
            }
        }
    }
    void Traversal()
    {
        int *visited=new int [n];
        int vertex;
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        cout<<"enter begining vertex= ";
        cin>>vertex;
        DFS_nonrec(visited,vertex);
    }
};
int main()
{
    Graph g;
    g.create_graph();
    g.read_graph_edge();
    g.print_graph();
    cout<<endl;
    g.Traversal();
    
}