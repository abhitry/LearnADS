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
    int colormyvertex(int v,int m,int color[])
    {
        if(v==n){
            int max=-1;
            for(int i=0;i<n;i++)
            {
                max=max<color[i]?color[i]:max;
            }
            return max+1;
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
            return 0;
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
        cout<<"minimum number of colors are = ";
        cout<<colormyvertex(0,m,color);
    }
};
int main()
{
    Graph g;
    g.readgraph_matrix();
    g.colormygraph();
}
