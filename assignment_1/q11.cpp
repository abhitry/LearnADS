#include<iostream>
using namespace std;
int reverse_num(int num,int rev)
{
    if(num==0)
    {
        return rev;
    }
    return reverse_num(num/10,rev*10+num%10);
}
int main()
{
    cout<<reverse_num(123,0);
}