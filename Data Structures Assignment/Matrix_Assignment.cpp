#include<iostream>

using namespace std;

class SparseMatrix
{
    int row,col;
    int matrix[10][10],sparse[10][3];
    
    public:
    void read_matrix();
    void create_sparse_matrix();
    void display_sparse();
    void transpose_matrix();
    void fast_transpose();
    void sparse_addition(SparseMatrix &o1,SparseMatrix &o2);
    
};


void SparseMatrix::read_matrix()
{
    int i,j;
    cout<<"Enter number of rows: ";
    cin>>row;
    cout<<"Enter number of columns: ";
    cin>>col;
    cout<<"Enter the matrix elements: "<<endl;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }
}

void SparseMatrix::create_sparse_matrix()
{
    int i,j,k=1;
    int count=0;
     for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(matrix[i][j]==0)
            count++;
        }
    }
    if(count>((row*col)/2))
    {
        cout<<"Matrix is a sparse matrix"<<endl;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(matrix[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][0]=row;
    sparse[0][1]=col;
    sparse[0][2]=k-1;
    }
    else
    {
        cout<<"Matrix is not a sparse matrix";
        exit(0);
    }
}

void SparseMatrix::display_sparse()
{
    int i,j;
    cout<<"Row "<<" Column "<<"   Value"<<endl;
    for(i=1;i<=sparse[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<sparse[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"----------------------------"<<endl;
}

void SparseMatrix::transpose_matrix()
{
    int transpose[10][3];
    int i,j,k=1;
    
    for(j=0;j<sparse[0][1];j++)
    {
        for(i=1;i<=sparse[0][2];i++)
        {
            if(sparse[i][1]==j)
            {
                transpose[k][0]=sparse[i][1];
                transpose[k][1]=sparse[i][0];
                transpose[k][2]=sparse[i][2];
                k++;
            }
        }
    }
    cout<<"Displaying transpose of matrix"<<endl;
    cout<<"Row "<<" Column "<<"   Value"<<endl;
    
    for(i=1;i<=sparse[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<transpose[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"----------------------------"<<endl;
}

void SparseMatrix::fast_transpose()
{
    int total[sparse[0][1]], index[sparse[0][1] +1];
    int transpose1[10][3];
    int loc,i,j,col_no;
    
    for(i=0;i<sparse[0][1];i++)
    {
        total[i] = 0;
    }
    
    for(i=1; i<=sparse[0][2];i++)
    {
        col_no = sparse[i][1];
        total[col_no]++;
    }
    
    index[0] = 1;
    
    for(i=1;i<=sparse[0][1];i++)
    {
        index[i]=index[i-1] + total[i-1];
    }
 
    transpose1[0][0] = sparse[0][1];
    transpose1[0][1] = sparse[0][0];
    transpose1[0][2] = sparse[0][2];
    
    for(i=1;i<=sparse[0][2];i++)
    {
        col_no = sparse[i][1];
        loc = index[col_no];
        transpose1[loc][0]=sparse[i][1];
        transpose1[loc][1]=sparse[i][0];
        transpose1[loc][2]=sparse[i][2];
        index[col_no]++;
    }
    
    cout<<"Displaying transpose of matrix using fast transpose algorithm"<<endl;
    cout<<"Row "<<" Column "<<"   Value"<<endl;
    for(i=1;i<=transpose1[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<transpose1[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"----------------------------"<<endl;
}

void SparseMatrix::sparse_addition(SparseMatrix &o1,SparseMatrix &o2)
{
    int l1,l2,i=1,j=1,k=1;
    int add[10][3];
    
    //checking rows and columns of both the matrix are equal or not
    
    if((o1.row != o2.row) || (o1.col != o2.col))
    {
        cout<<"Rows and Columns does not match"<<endl;
        cout<<"Try again"<<endl;
    }
    
    else
    {
        l1=o1.sparse[0][2];                                    //number of non zero elements of matrix 1
        l2=o2.sparse[0][2];                                    //number of non zero elements of matrix 2
        add[0][0]=o1.sparse[0][0];
        add[0][1]=o1.sparse[0][1];
        
        while(i<=l1 && j<=l2)
        {
            if(o1.sparse[i][0] == o2.sparse[j][0])             //comparing row terms
            {
                if(o1.sparse[i][1] == o2.sparse[j][1])         //comparing column terms
                {
                    add[k][0] = o1.sparse[i][0];
                    add[k][1] = o1.sparse[i][1];
                    add[k][2] = o1.sparse[i][2] + o2.sparse[j][2];
                    i++;
                    j++;
                    k++;
                }
                else
                {
                    if(o1.sparse[i][1] < o2.sparse[j][1])
                    {
                        add[k][0] = o1.sparse[i][0];
                        add[k][1] = o1.sparse[i][1];
                        add[k][2] = o1.sparse[i][2];
                        i++;
                        k++;
                    }
                    else
                    {
                        if(o1.sparse[i][1] < o2.sparse[j][1])
                        {
                            add[k][0] = o2.sparse[j][0];
                            add[k][1] = o2.sparse[j][1];
                            add[k][2] = o2.sparse[j][2];
                            j++;
                            k++;
                        }
                    }
                }
            }
            else
            {
                if(o1.sparse[i][0] > o2.sparse[j][0])
                {
                    add[k][0] = o2.sparse[j][0];
                    add[k][1] = o2.sparse[j][1];
                    add[k][2] = o2.sparse[j][2];
                    j++;
                    k++;
                }
                else
                {
                    if(o1.sparse[i][0] < o2.sparse[j][0])
                    {
                        add[k][0] = o1.sparse[i][0];
                        add[k][1] = o1.sparse[i][1];
                        add[k][2] = o1.sparse[i][2];
                        i++;
                        k++;
                    }
                }
            }
        }
        
        while( (i>=l1) && (j<=l2))                            //adding remaining j terms of matrix to addition matrix
        {
            add[k][0] = o2.sparse[j][0];
            add[k][1] = o2.sparse[j][1];
            add[k][2] = o2.sparse[j][2];
            j++;
            k++;
        }
        while((i<=l1) && (j>=l2))                             //adding remaining i terms of matrix to addition matrix
        {
            add[k][0] = o1.sparse[i][0];
            add[k][1] = o1.sparse[i][1];
            add[k][2] = o1.sparse[i][2];
            i++;
            k++;
        }
        add[0][2]=k-1;
        
        cout<<"Addition Matrix:"<<endl;
        cout<<"Row "<<" Column "<<"   Value"<<endl;
        for(i=1;i<=add[0][2];i++)
        {
            for(j=0;j<3;j++)
            {
                cout<<add[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"----------------------------"<<endl;
    }
    
}

int main()
{
    int choice;
    SparseMatrix o1,o2;
    
    cout<<"\tYou can perform following operations"<<endl;
    cout<<"\tEnter the appropriate choice: "<<endl;
    cout<<"\t1.Create Matrix"<<endl; 
    cout<<"\t2.Convert matrix to sparse matrix"<<endl; 
    cout<<"\t3.Transpose of Sparse matrix using simple transpose"<<endl;
    cout<<"\t4.Transpose of Sparse matrix using fast transpose"<<endl;
    cout<<"\t5.Addition of sparse matrix"<<endl;
    cout<<"\t6.Exit"<<endl;
    do{
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter the details of matrix1:"<<endl;
                o1.read_matrix();
                cout<<"Matrix entered successfully"<<endl;
                break;
            case 2:
                o1.create_sparse_matrix();
                o1.display_sparse();
                break;
            case 3:
                o1.transpose_matrix();
                break;
            case 4:
                o1.fast_transpose();
                break;
            case 5:
                cout<<"Enter second matrix for addition"<<endl;
                o2.read_matrix();
                cout<<"Matrix entered successfully"<<endl;
                o2.create_sparse_matrix();
                o2.display_sparse();
                o1.sparse_addition(o1,o2);
                break;
            case 6:
            break;
            default:
                cout<<"\nEnter valid choice";
                break;
        }

    }while(choice!=6);
    return 0;
    
}
