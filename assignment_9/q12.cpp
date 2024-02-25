#include<iostream>
#include<numeric>
using namespace std;
int add(int sum,int x)
{
    return sum+x;
}
int main()
{
    vector<int>vct[4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            vct[i].push_back(i+j);
        }
    }
    for(int i=0;i<4;i++)
    {
        int sum;
        sum=accumulate(vct[i].begin(),vct[i].end(),0,add);
        cout<<sum<<"    ";
    }
}