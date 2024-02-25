#include<iostream>
using namespace std;
class Graph
{
    public:
    vector<vector<int> >graph;
    int start,wt,n;
    bool dir;
    Graph()
    {
        cout<<"enter vertices= ";
        cin>>n;
        cout<<"is it directed= ";
        cin>>dir;
        cout<<"is it weighted= ";
        cin>>wt;
        int i,j;
        for(i=0;i<n;i++)
        {
            vector<int>subvct;
            for(j=0;j<n;j++)
            {
                subvct.push_back(0);
            }
            graph.push_back(subvct);
        }    
    }
    void readgraph_matrix()
    {
        cout<<"enter matrix= ";
        int i,j;
        vector<vector<int> >::iterator itr;
        itr=graph.begin();
        vector<int>::iterator subitr;
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
    void dregree()
    {
        int i,j,count;
        vector<vector<int> >::iterator itr;
        itr=graph.begin();
        i=0;
        vector<int>::iterator subitr;
        while(itr!=graph.end())
        {
            count=0;
            subitr=(*itr).begin();
            while(subitr!=(*itr).end())
            {
                if(*subitr!=0)
                {
                    count++;
                }
                subitr++;
            }
            cout<<"degree= "<<i++ <<"is "<<count<<endl;
            itr++;
        }
    }
};
int main()
{
    Graph g;
    g.readgraph_matrix();
    g.dregree();
}