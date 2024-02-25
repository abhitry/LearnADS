#include<iostream>
using namespace std;
int  main()
{
    int n;
    cout<<"enter vectices= ";
    cin>>n;
    vector<int>graph[n];
    bool wt;
    bool dir;
    int start;
    cout<<"is it weighted= ";
    cin>>wt;
    cout<<"is it directed= ";
    cin>>dir;
    int i,j;
    for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i].push_back(0);
        }
    }
    cout<<"enter matrix= ";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    int count;
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
        cout<<"degree of  "<<i<<" is = " <<count<<endl;
    }
    
}