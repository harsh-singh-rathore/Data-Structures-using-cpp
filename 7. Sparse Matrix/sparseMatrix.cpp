#include <iostream>
#define MAX_TERMS 101

using namespace std;

struct sparseMatrix
{
    int row;
    int col;
    int value;
} term[MAX_TERMS];

void InsertMatrix(sparseMatrix mat[], int row, int col) {
    int k=0;
    int value;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout<<"Enter "<<i<<", "<<j<<": ";
            cin>>value;
            if(value != 0) {
                mat[k+1].col = j;
                mat[k+1].row = i;
                mat[k+1].value = value;
                k++;
            }
        }
    }
    mat[0].col = col;
    mat[0].row = row;
    mat[0].value = k;
}
void ExpandSparseMatrix(sparseMatrix mat[]) {
    int k=1;
    for(int i=0; i<mat[0].row; i++) {
        for(int j=0; j<mat[0].col; j++) {
            if(mat[k].row == i && mat[k].col == j) {
                cout<<mat[k].value<<" ";
                k++;
            }
            else
                cout<<0<<" ";
        } cout<<endl;
    }
}
void TransposeSparseMatrix(sparseMatrix mat[], sparseMatrix transpose[]) {
    int i, j, currentB;
    transpose[0].value = mat[0].value;
    transpose[0].col = mat[0].row;
    transpose[0].row = mat[0].col;
    if(transpose[0].value>0) {
        currentB = 1;
        for(i=0; i<transpose[0].row; i++) {
            for(j=1; j<=transpose[0].value; j++){
                if(mat[j].col == i) {
                    transpose[currentB].row = mat[j].col;
                    transpose[currentB].col = mat[j].row;
                    transpose[currentB].value = mat[j].value;
                    currentB++;
                }
            }
        }
    }
}

void FastTranspose(sparseMatrix a[], sparseMatrix b[])
{
    int row_terms[MAX_TERMS], starting_pos[MAX_TERMS];
    int i, j, num_cols=a[0].col, num_terms=a[0].value;
    b[0].row=num_cols;
    b[0].col=a[0].row;
    b[0].value=num_terms;

    if(num_terms>0) {
        for(i=0; i<num_cols; i++) {
            row_terms[i]=0;
        }
        for(i=1; i<=num_terms; i++) {
            row_terms[a[i].col]++;
        }
        starting_pos[0]=1;
        for(i=1; i<num_cols; i++) {
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }
        for(i=1; i<=num_terms; i++){
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}




int main()
{
    InsertMatrix(term, 3, 3);
    ExpandSparseMatrix(term);
    cout<<endl;
    sparseMatrix transpose[term[0].row*term[0].col];
    sparseMatrix transpose1[term[0].row*term[0].col];
    TransposeSparseMatrix(term, transpose);
    ExpandSparseMatrix(transpose);
    FastTranspose(term, transpose1);
    ExpandSparseMatrix(transpose1);
    return 0;
}