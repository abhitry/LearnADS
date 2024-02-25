#include<iostream>
using namespace std;
class Employee
{
    public:
    string name,hometown,company;
    void scan()
    {
        cout<<"enter name= ";
        getline(cin,name);
        cout<<"enter hometown= ";
        getline(cin,hometown);
        cout<<"enter company= ";
        getline(cin,company);
    }
    bool compare(string str)
    {
        if(company==str)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Employee emp[3];
    int i;
    for( i=0;i<3;i++)
    {
        emp[i].scan();
    }
    string s;
    cout<<"enter companyname to searxh= ";
    getline(cin,s);
    bool res;
    for( i=0;i<3;i++)
    {
        if(emp[i].compare(s))
        {
            cout<<"found";
            break;
        }
    }   
    if(i==3)
    {
        cout<<"not found";
    }
}