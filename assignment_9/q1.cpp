#include<iostream>
#include<vector>
using namespace std;
class table
{
    public:
    int x;
    vector<int>v;
    table()
    {
        cout<<"enter number to get table of = ";
        cin>>x;
        for(int i=1;i<=10;i++)
        {
            v.push_back(x*i);
        }
    }
    void show()
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }
};
int main()
{
    table tab;
    vector<table>v;
    v.push_back(tab);
    v[0].show();
}