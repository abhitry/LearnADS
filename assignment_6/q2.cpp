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
    void insertedge(int u,int v,int w)
    {
        graph[u][v]=w;
        if(dir==0)
        {
            graph[v][u]=w;
        }
    }
    void readgraph_edge()
    {
        cout<<"enter edge u,v,w or enter (-1,-1) to stop=";
        int u,v,w;
        while(1)
        {
            cin>>u>>v>>w;
            if (u==-1 || v==-1 ||w==-1)
            {
                break;
            }
            insertedge(u,v,w);
        }
    }
    void outdegree()
    {
        int i,j,count;
        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<n;j++)
            {
                if(graph[i][j]!=0)
                {
                    count++;
                }
            }
            cout<<"outdegree of "<<i <<" = "<<count<<endl;
        }
    }
    void indegree()
    {
        int i,j,count;
        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<n;j++)
            {
                if(graph[j][i]!=0)
                {
                    count++;
                }
            }
            cout<<"indegree of "<<i <<" = "<<count<<endl;
        }
    }
    void findegree()
    {
        if(dir==0)
        {
            outdegree();
        }
        else{
            indegree();
            outdegree();
        }
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
    g.findegree();
}