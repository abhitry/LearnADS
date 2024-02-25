#include<iostream>
using namespace std;
int main()
{
    vector<int>vct[3];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
        {
            vct[i].push_back(i+j);
        }
    }
    vector<int>::iterator itr;
    for(int i=0;i<3;i++)
    {
        itr=vct[i].begin();
        while(itr!=vct[i].end())
        {
            cout<<*itr<<" ";
            itr++;
        }
        cout<<endl;
    }
}