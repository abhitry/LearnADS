#include<iostream>
#include<numeric>
using namespace std;
float addition(float sum,float curval)
{
    
        return sum+curval;
}
int main()
{
    float f;
    vector<float>v;
    while(1)
    {
        cout<<"enter fration= ";
        cin>>f;
        if(f==0)
        {
            break;
        }
        v.push_back(f);
    }
    sort(v.begin(),v.end());
    vector<float>::iterator itr=v.begin();
    while(itr!=v.end())
    {
        cout<<*itr<<" ";
        itr++;
    }
    float sum=0.0;
    sum=accumulate(v.begin(),v.end(),0.0,addition);
    cout<<endl<<sum;
}