#include<iostream>
using namespace std;
class Graph
{
    vector<vector<int> > graph;
    int wt,n,start;
    bool dir;
    public:
    Graph()
    {
        cout<<"enter number of vertices= ";
        cin>>n;
        cout<<" is it weighted= ";
        cin>>wt;
        cout<<"is it directed= ";
        cin>>dir;
        int i=0,j;
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
        vector<vector<int> > ::iterator itr=graph.begin();
        vector<int>::iterator subitr;
        cout<<"entrer matrix= ";
        while(itr!=graph.end())
        {
            subitr=(*itr).begin();
            while(subitr!=(*itr).end())
            {
                cin>>*subitr;
                subitr++;
            }
            itr++;
        }
    }
    void warshalls()
    {
        vector<vector<int> >TC(graph);
        int i,j,k;
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(TC[i][j]==0)
                    {
                        if(TC[i][k]==1 && TC[k][j]==1)
                        {
                            TC[i][j]=1;
                        }
                    }
                }
            }
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<TC[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.readgraph_matrix();
    g.warshalls();
}