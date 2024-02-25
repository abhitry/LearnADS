#include<iostream>
#include<numeric>
using namespace std;
int  scan(int sum,int &curval)
{
    cout<<"enter vector values= ";
    cin>>curval;
    return sum;
}
int  print(int sum,int curval)
{
    cout<<curval;
    return sum;
}
int main()
{
    vector<vector<int> >v(5,vector<int>(3,1));
    //int sum;
    for(int i=0;i<5;i++)
    {
        int sum;
        sum=accumulate(v[i].begin(),v[i].end(),0,scan); 
    }
    for(int i=0;i<5;i++)
    {
        int sum;
        sum=accumulate(v[i].begin(),v[i].end(),0,print); 
        cout<<endl;   
    }

}