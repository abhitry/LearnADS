#include<iostream>
using namespace std;
int main()
{
    vector<int>vct[3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            vct[i].push_back(j+i);
        }
    }
    int sum=0;
    for(int i=0;i<3;i++)
    {
        sum=0;
        for(int j=0;j<4;j++)
        {
            sum=sum+vct[i][j];
        }
        cout<<sum<<endl;
    }
}