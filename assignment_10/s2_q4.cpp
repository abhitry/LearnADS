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
        }
        return true;
    }
    void colormyvertex(int &count,int v,int m,int color[],string s[])
    {
        if(v==n)
        {
            //print
            for(int i=0;i<n;i++)
            {
                cout<<s[color[i]]<<" ";
            }
            count++;
            cout<<endl;
        }
        else{
            int clr;
            for(clr=0;clr<m;clr++)
            {
                if(canicolor(v,clr,color))
                {
                    color[v]=clr;
                    colormyvertex(count,v+1,m,color,s);
                }
            }
            color[v]=-1;
        }
    }
    void colourmygraph()
    {
        int m,*color;
        cout<<"enter number of colors= ";
        cin>>m;
        color=new int[n];
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        int count=0;
        string *s=new string [m];
        cin.ignore(1);
        for(int i=0;i<m;i++)
        {
            cout<<"enter colr= ";
            getline(cin,s[i]);
        }
        colormyvertex(count,0,m,color,s);
        cout<<"count is "<<count<<endl;
    }
};

int main()
{
    
    Graph g;
    g.readgraph_matrix();
    g.colourmygraph();
}