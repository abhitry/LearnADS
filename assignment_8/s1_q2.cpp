#include<iostream>
using namespace std;
class Matrix
{
    public:
    int **mat;
    int n;
    Matrix()
    {
        cout<<"enter number of vertices= ";
        cin>>n;
        mat=new int *[n];
        for(int i=0;i<n;i++)
        {
            mat[i]=new int [n];
        }
    }
    void create()
    {
        int i,j;
        cout<<"enter your matrix= ";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        }
    }
    Matrix operator+(Matrix &bat)
    {
        Matrix res;
        for(int i=0;i<n;i++)
        {
            for(int  j=0;j<n;j++)
            {
                res.mat[i][j]=mat[i][j]+bat.mat[i][j];
            }
        }
        return res;
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            for(int  j=0;j<n;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    Matrix operator*(Matrix & bat)
    {
        Matrix res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                res.mat[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    res.mat[i][j]+=mat[i][k]* bat.mat[k][j];
                }
            }
        }
        return res;
    }
};
int main()
{
    Matrix m;
    m.create();
    Matrix b;
    b.create();
    Matrix r;
    r=m+b;
    r.print();
    cout<<endl;
    r=m*b;
    r.print();

    // int mat[10][10];
    // int bat[10][10];
    // int i,j;
    // int n;
    // cout<<"enter number of vertices= ";
    // cin>>n;
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         cin>>mat[i][j];
    //     }
    // }
    // cout<<"enter another matrix = ";
    //  for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         cin>>mat[i][j];
    //     }
    // }
    // int res[10][10];
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         res[i][j]=mat[i][0]*bat[0][j]  +mat[i][1]*bat[1][j]+
    //         mat[i][2]*bat[2][j];
    //     }
    // }
    //     for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         cout<<res[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }
}