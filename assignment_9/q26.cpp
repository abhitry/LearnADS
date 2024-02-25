#include<iostream>
using namespace std;
class Student 
{
    public:
    string name;
    void scan()
    {
        cout<<"enter name= ";
        getline(cin,name);
    }
    bool operator==(string str)
    {
        if(name==str)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        cout<<name;
    }
};
int main()
{
    vector<Student> std;
    int i;
    Student s;
    for(i=0;i<3;i++)
    {
        s.scan();
        std.push_back(s);
    }
    vector<Student>::iterator loc;
    cout<<"enter name to search== ";
    s.scan();
    loc=find(std.begin(),std.end(),s.name);
    if(loc==std.end())
    {
        cout<<"not found";
    }
    else{
        cout<<"found";
    }
}