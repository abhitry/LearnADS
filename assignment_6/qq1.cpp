#include<iostream>
using namespace std;
class Graphmat
{
    public:
    int  **graph;
    bool wt;
    bool dir;
    int n;
    int start;
    Graphmat()
    {
        n=0;
        graph=NULL;
    }
    void creategraph()
    {
        cout<<"enter vertices= ";
        cin>>n;
        cout<<"is it directed= ";
        cin>>dir;
        cout<<"is it weighted= ";
        cin>>wt;
        cout<<"enter start= ";
        cin>>start;
        graph=new int* [n];
        int i,j;
        for( i=0;i<n;i++)
        {
            graph[i]=new int [n];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                graph[i][j]=0;
                //*(graph[i]+j)=0;
            }
        }
    }
    void readgraph_mat()
    {
        int i,j;
        cout<<"enter graph= ";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
    }
    void printgraph()
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void insertedge(int u,int v)
    {
        graph[u][v]=1;
        if(dir==0)
        {
            graph[v][u]=1;
        }
    }
    void readgraph_edge()
    {
        cout<<"enter edge u,v or enter (-1,-1) to stop=";
        int u,v;
        while(1)
        {
            cin>>u>>v;
            if (u==-1 || v==-1)
            {
                break;
            }
            insertedge(u,v);
        }
    }
    void DFS_rec(int *visited,int v)
    {
        cout<<v<<"visited"<<endl;
        visited[v]=1;
        for(int i=0;i<n;i++)
        {
            if(graph[v][i]!=0 && visited[i]==0)
            {
                DFS_rec(visited,i);
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
        DFS_rec(visited,vertex);
    }

};
int main()
{
    Graphmat g;
    g.creategraph();
    g.readgraph_edge();
    cout<<endl;
    g.printgraph();
    cout<<endl;
    g.Traversal();

}