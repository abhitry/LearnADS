#include<iostream>
using namespace std;
class Distance
{
    public:
    int km,mtr;
    void scan()
    {
        cout<<"enter km= ";
        cin>>km;
        cout<<"enter mtr= ";
        cin>>mtr;
    }
    void print()
    {
        cout<<km*1000+mtr<<endl;
    }
};
int main()
{
    vector<Distance>v;
    Distance dist;
    for(int i=0;i<3;i++)
    {
        dist.scan();
        v.push_back(dist);
    }
    for(int i=0;i<3;i++)
    {
        v[i].print();
    }
}