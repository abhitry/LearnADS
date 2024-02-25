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
        cout<<"enter number of vertices= ";
        cin>>n;
        cout<<"is it directed= ";
        cin>>dir;
        cout<<"is it weigjhted= ";
        cin>>wt;
        vector<int>subvct(n,0);
        for(int i=0;i<n;i++)
        {
            graph.push_back(subvct);
        }
    }
    void readmatrix()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.readmatrix();
    g.print();
}