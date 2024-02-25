#include<iostream>
using namespace std;
class Graph
{
    int **graph;
    int wt,n,start;
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
        graph=new int *[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new int[n];
        }
    }
    void readgraph_matrix()
    {
        int i,j;
        cout<<"enter matrix= ";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
    }
    bool canicolor(int v,int clr,int color[])
    {
        for(int i=0;i<n;i++)
        {
            if(graph[v][i]!=0 && color[i]==clr)
            {
                return false;
            }
        }return true;
    }
    bool colormyvertex(int v,int m,int color[])
    {
        if(v==n){
            return true;
        }
        else{
            int clr;
            for(clr=0;clr<m;clr++)
            {
                if(canicolor(v,clr,color))
                {
                    color[v]=clr;
                    return colormyvertex(v+1,m,color);
                }
            }
            color[v]=-1;
            return false;
        }
    }
    void colormygraph()
    {
        int m ,*color;
        color=new int [n];
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        cout<<"enter number of colors= ";
        cin>>m;
        if(colormyvertex(0,m,color))
        {
            cout<<"\nenough";
        }
        else{
            cout<<"\nnot enough";
        }
    }
};
int main()
{
    Graph g;
    g.readgraph_matrix();
    g.colormygraph();
}
