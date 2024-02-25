#include<iostream>
using namespace std;
int main()
{
    int n=29;
    vector<int>v;
    int i=0;
    int num=n;
    v.push_back(1);
    for(i=2;i<=num;i++)
    {
        while(num%i==0)
        {
            v.push_back(i);
            num=num/i;
        }
    }
    i=0;
    while(i<v.size())
    {
        cout<<v[i]<< " ";
        i++;
    }
}