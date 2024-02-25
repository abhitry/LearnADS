#include<iostream>
using namespace std;
class Item
{
    public:
    int weight,profit;
};
float cmp(Item i1,Item i2)
{
    float a,b;
    a=i1.profit/(float)i1.weight;
    b=i2.profit/(float)i2.weight;
    return a>b;
}
int main()
{
    int n ;
    cout<<"enter number of itemds= ";
    cin>>n;
    int w;
    cout<<"enter weight= ";
    cin>>w;
    vector<Item>items(n);
    for(int i=0;i<n;i++)
    { 
        cout<<"enter profit=";
        cin>>items[i].profit;
        cout<<"enter weight= ";
        cin>>items[i].weight;
    }
    sort(items.begin(),items.end(),cmp);
    float maxprofit=0.0;
    for(int i=0;i<n;i++)
    {
        if(items[i].weight<=w)
        {
            maxprofit=maxprofit+items[i].profit;
            w=w-items[i].weight;
        }
        else
        {
            maxprofit=maxprofit+w*(items[i].profit/(float)items[i].weight);
            w=0;
        }
    }
    cout<<maxprofit;
}