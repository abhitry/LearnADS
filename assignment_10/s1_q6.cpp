#include<iostream>
using namespace std;
class Graph
{
    vector<vector<int> > graph;
    int wt,start,n;
    bool dir;
    public:
    Graph()
    {
        cout<<"enter vertices= ";
        cin>>n;
        cout<<"is it weighted= ";
        cin>>wt;
        cout<<"is it directed= ";
        cin>>dir;
        int i,j;
        vector<int>subvct;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                subvct.push_back(0);
            }
            graph.push_back(subvct);
            subvct.clear();
        }
    }
    void readgraph_matrix()
    {
        int i,j;
        cout<<"enterr matrix= ";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
    }
    void degree()
    {
        int i,j,count;
        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<n;j++)
            {
                if(graph[i][j!=0])
                {
                    count++;
                }
            }
            cout<<"degree of  "<<i<<"is = "<<count<<endl;
        }
    }
    void traversal()
    {
        int *visited=new int [n];
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        int vertex;
        cout<<"enter vertex to start= ";
        cin>>vertex;
        DFS_rec(visited,vertex);
    }
    void DFS_rec(int *visited,int v)
    {
        cout<<v<<"visited \n";
        visited[v]=1;
        for(int i=0;i<n;i++)
        {
            if(graph[v][i]!=0 && visited[i]==0)
            {
                DFS_rec(visited,i);
            }
        }
    }
};
int main()
{
    Graph g;
    g.readgraph_matrix();
    g.degree();
    g.traversal();
}