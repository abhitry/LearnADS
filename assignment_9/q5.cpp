#include<iostream>
#include<vector>
using namespace std;
int main()
{
    class table
    {
        public:
        int num;
        vector<int>v;
        table()
        {

        }
        table(int a)
        {
            num=a;
            for(int i=0;i<=10;i++)
            {
                v.push_back(a*i);
            }
        }
        void show()
        {
            vector <int>::iterator itr;
            itr=v.begin();
            while(itr!=v.end())
            {
                cout<<*itr<<" ";
                itr++;
            }
        }
    };
    int x;
    vector<table>v;
    for(int i=0;i<5;i++)
    {
        cout<<"enter number = ";
        cin>>x;
        table tab(x);
        v.push_back((tab));
    }
    for(int i=0;i<5;i++)
    {
        cout<<v[i].num<<"        ";
        v[i].show();
        cout<<endl;

    }
}