#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

bool check_sparse(int ,int ,int);
void show_sparse(int [][3],int n);
int main()
{
    int row1,col1;
    int row2,col2;
    cout<<"please Enter Row of matrix 1 : ";
    cin>>row1;
    cout<<"please Enter col of matrix 1 : ";
    cin>>col1;
    cout<<"\nplease Enter Row of matrix 2 : ";
    cin>>row2;
    cout<<"please Enter col of matrix 2 : ";
    cin>>col2;

    if(col1!=row2)
    {
        cout<<"Multiplication is not possible!";
    }
    else
    {
        system("CLS");

        int counter1=0,counter2=0;
        int matrix1[row1][col1];
        int matrix2[row2][col2];

        cout<<"Matrix one : "<<row1<<"*"<<col1<<"\n\n";
        for(int i=0;i<row1;i++)//for matrix 1
        {
            for(int j=0;j<col1;j++)
            {
                cout<<"Enter element of R: "<<i<<" , C: "<<j<<" = ";
                cin>>matrix1[i][j];
                if(matrix1[i][j]==0)
                    counter1++;
            }
        }



        cout<<"\n\nMatrix two : "<<row2<<"*"<<col2<<"\n\n";
        for(int i=0;i<row2;i++)//matrix 2
        {
            for(int j=0;j<col2;j++)
            {
                cout<<"Enter element of R: "<<i<<" , C: "<<j<<" = ";
                cin>>matrix2[i][j];
                if(matrix2[i][j]==0)
                    counter2++;

            }
        }

int True=0;
//check sparse 1:
    if(check_sparse(counter1,row1,col1)==1)
    {
        cout<<"Matrix one is sparse"<<endl;
        True++;
    }
    else
        cout<<"Matrix one is not sparse!"<<endl;


//check sparse 2:
    if(check_sparse(counter2,row2,col2)==1)
    {
        cout<<"Matrix two is sparse"<<endl;
        True++;
    }
    else
        cout<<"Matrix two is not sparse!"<<endl;


    if(True!=2)
    cout<<"sparse multiplication is not possible!"<<endl;
    else
    {
    //create sparse 1:
        int nvalue1=row1*col1-counter1;
        int sparse1[nvalue1+1][3];

        sparse1[0][0]=row1;
        sparse1[0][1]=col1;
        sparse1[0][2]=nvalue1;
        int z=1;

        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                if(matrix1[i][j]!=0)
                {
                    sparse1[z][0]=i;
                    sparse1[z][1]=j;
                    sparse1[z][2]=matrix1[i][j];
                    z++;
                }
            }
        }
    //show sparse 1:
    // show_sparse(sparse1[][3],nvalue1);
    cout<<"\nRow:"<<row1<<"\tCol:"<<col1<<"\tValue:"<<nvalue1<<endl;
        for(int i=1;i<=nvalue1;i++)
        {
            for(int j=0;j<3;j++)
                cout<<sparse1[i][j]<<"\t";
            cout<<endl;
        }



    //create sparse 2:
        int nvalue2=row2*col2-counter2;
        int sparse2[nvalue2+1][3];

        sparse2[0][0]=row2;
        sparse2[0][1]=col2;
        sparse2[0][2]=nvalue2;
        z=1;

        for(int i=0;i<row2;i++)
        {
            for(int j=0;j<col2;j++)
            {
                if(matrix2[i][j]!=0)
                {
                    sparse2[z][0]=i;
                    sparse2[z][1]=j;
                    sparse2[z][2]=matrix2[i][j];
                    z++;
                }
            }
        }

    //show sparse 2:
    // show_sparse(sparse1[][3],nvalue1);
        cout<<"\nRow:"<<row2<<"\tCol:"<<col2<<"\tValue:"<<nvalue2<<endl;
        for(int i=1;i<=nvalue2;i++)
        {
            for(int j=0;j<3;j++)
                cout<<sparse2[i][j]<<"\t";
            cout<<endl;
        }

    int matrix[row1][col2]={};
    //sparse multiplication:
    int row,col;
    for(int i=1;i<=nvalue1;i++)
    {
        for(int j=1;j<=nvalue2;j++)
        {
            if(sparse1[i][1]==sparse2[j][0])
            {
                row=sparse1[i][0];
                col=sparse2[j][1];
                matrix[row][col]=matrix[row][col]+(sparse1[i][2]*sparse2[j][2]);
            }
        }
    }


    cout<<"\n\nMultiplication matrix : "<<row1<<"*"<<col2<<endl;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }


    }

}

    return 0;
}

bool check_sparse(int counter,int row,int col)
{
    if(counter>=row*col/2)
        return true;
    else
        return false;

}
