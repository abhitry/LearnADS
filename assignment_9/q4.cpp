#include<iostream>
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
            for(int i=1;i<=10;i++)
            {
                v.push_back(a*i);
            }
        }
        void show()
        {
            vector<int>::iterator itr;
            itr=v.begin();
            while(itr!=v.end())
            {
                cout<<*itr<<" ";
                itr++;
            }
        }
    };
    int x;
    cout<<"enter number = ";
    cin>>x;
    table tab(x);
    tab.show();
}