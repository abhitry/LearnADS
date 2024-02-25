#include<iostream>
using namespace std;
class City
{
    public:
    string name;
    void scan()
    {
        cout<<"enter cityname or STOP to stop=  ";
        getline(cin,name);
    }
    bool compare(string s)
    {
        if(name==s)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        cout<<name;
    }
    int check(City s)
    {
        if(name>s.name)
        {
            return 1;
        }
        return 0;
    }
};
bool comparator(City c1,City c2)
{
    return (c1.name<c2.name);
}
int main()
{
    vector<City> c;
    vector<City>::iterator itr;
    City cityname;
    while(1)
    {
        cityname.scan();
        if(cityname.name=="STOP")
        {
            break;
        }
        itr=c.begin();
        int res;
        while(itr!=c.end())
        {
            res=(*itr).compare(cityname.name);
            if(res==1)
            {
                break;
            }
            itr++;
        }
        if(res==0)
        {
            c.push_back(cityname);
        }
    }
    itr=c.begin();
    while(itr!=c.end())
    {
        (*itr).print();
        cout<<" ";
        itr++;
    }
    cout<<"enter name to be deleteed= ";
    cityname.scan();
    itr=c.begin();
    while(itr!=c.end())
    {
        if((*itr).compare(cityname.name))
        {
            c.erase(itr);
        }
        itr++;
    }
    cout<<endl;
    itr=c.begin();
    while(itr!=c.end())
    {
        (*itr).print();
        cout<<" ";
        itr++;
    }
    cout<<endl;
    sort(c.begin(),c.end(),comparator);
    // vector<City>::iterator j;
    // for(itr=c.begin();itr<c.end()-1;itr++)
    // {
    //     for(j=itr+1;j<c.end();j++)
    //     {
    //         if((*itr).check(*j))
    //         {
    //             swap((*itr).name,(*j).name);
    //         }
    //     }
    // }
    itr=c.begin();
    while(itr!=c.end())
    {
        (*itr).print();
        cout<<" ";
        itr++;
    }
}