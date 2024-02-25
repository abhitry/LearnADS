#include<iostream>
using namespace std;
class Graph
{
    vector<vector<int> >graph;
    int wt;
    bool dir;
    int n;
    public:
    Graph()
    {
        cout<<"enter vertices= ";
        cin>>n;
        cout<<"is it weightted = ";
        cin>>wt;
        cout<<"is it directed= ";
        cin>>dir;
        vector<int>subvct;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                subvct.push_back(0);
            }
            graph.push_back(subvct);
            subvct.clear();
        }
    }  
    void readgraph_matrix()
    {
        vector<vector<int> >::iterator itr;
        vector<int>::iterator subitr;
        itr=graph.begin();
        cout<<"enter matrix= ";
        while(itr!=graph.end())
        {
            subitr=(*itr).begin();
            while(subitr!=(*itr).end())
            {
                cin>>*subitr;
                subitr++;
            }
            itr++;
            cout<<endl;
        }
    } 
    void outdegree()
    {
        int i,j,count;
        vector<vector<int> >::iterator itr;
        vector<int>::iterator subitr;
        itr=graph.begin();
        i=0;
        while(itr!=graph.end())
        {
            subitr=(*itr).begin();
            count=0;
            while(subitr!=(*itr).end())
            {
                if(*subitr!=0)
                {
                    count++;
                }
                subitr++;
            }
            cout<<"outdegree of "<<i++ <<"is = "<<count<<endl;
            itr++;
        }
    }
    void indegree()
    {
        int i,j,count;
        vector<vector<int> >::iterator itr;
        vector<int>::iterator subitr;
        for(i=0;i<n;i++)
        {
            count=0;
            itr=graph.begin();
            while(itr!=graph.end())
            {
                subitr=(*itr).begin();
                if(*(subitr+i)!=0)
                {
                    count++;
                }
                itr++;
            }
            cout<<"indegree of "<<i<<"is = "<<count<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.readgraph_matrix();
    g.outdegree();
    g.indegree();
}