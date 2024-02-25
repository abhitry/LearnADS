#include<iostream>
using namespace std;
int main()
{
    vector<vector<int> >v(5);
    vector<int>subvct;
    int x;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            subvct.push_back(j);
        }
        v[i]=(subvct);
        subvct.clear();
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}