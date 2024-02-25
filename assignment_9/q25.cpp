#include<iostream>
using namespace std;
class Student
{
    public:
    string name;
};
int main()
{
    vector<Student>std;
    Student s;
    for(int i=0;i<3;i++)
    {
        cout<<"enter name= ";
        //cin.getline(s.name,29);
        getline(cin,s.name);
        std.push_back(s);
    }
    cout<<"enter name to searchj= ";
    //cin.getline(s.name,29);
    getline(cin,s.name);
    for(int i=0;i<3;i++)
    {
        if((s.name==std[i].name))
        {
            cout<<"yes\n";
        }
    }
    vector<Student>::iterator loc;
    loc=find(std.begin(),std.end(),s);
    if(loc==std.end())
    {
        cout<<"not found";
    }
    else{
        cout<<"found";
    }
}
