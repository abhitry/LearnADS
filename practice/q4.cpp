#define MAX 10
#include<iostream>
using namespace std;
void slow_transpose(int sparse[][3],int strans[][3])
{
    strans[0][0]=sparse[0][1];
    strans[0][1]=sparse[0][0];
    int k=0;
    for(int i=0;i<sparse[0][1];i++)
    {
        for(int j=0;j<sparse[0][2];j++)
        {
            if(sparse[j][1]==i)
            {
                strans[k][0]=sparse[j][1];
                strans[k][1]=sparse[j][0];
                strans[k][2]=sparse[j][2];
                k++;
            }
        }
    }
}
void fast_transpose(int sparse[][3],int ftrans[][3])
{
    ftrans[0][0]=sparse[0][1];
    ftrans[0][1]=sparse[0][0];
    ftrans[0][2]=sparse[0][2];
    int rows=ftrans[0][0];
    int *total=new int[rows];
}
void print(int sparse[][3],int k,int col)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
   int original[10][10];
   int sparse[10][3];
   int row,col;
   cout<<"enter number of rows and columns=";
   cin>>row>>col;
   for(int i=0;i<row;i++)
   {
    for(int j=0;j<col;j++)
    {
        cin>>original[row][col];
    }
   }
    sparse[0][0]=row;
    sparse[0][1]=col;
    int k=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(original[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=original[i][j];
                k++;
            }
        }
    }
    sparse[0][2]=k-1;
    int strans[10][3];
    slow_transpose(sparse,strans);
    fast_transpose(sparse,strans);
    print(strans,strans[0][2],3);
}