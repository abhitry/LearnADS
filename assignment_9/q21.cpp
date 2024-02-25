#include<iostream>
using namespace std;
int main()
{
    vector<vector<int> >vct(2,vector<int>(4,1));
    // vector<int> subvct(4,1);
    // vct[0]=subvct;
    // vct[1]=subvct;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<vct[i][j]<<" ";
        }
        cout<<endl;
    }

}