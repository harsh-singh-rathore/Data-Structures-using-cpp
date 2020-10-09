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

int main()
{
    InsertMatrix(term, 3, 3);
    ExpandSparseMatrix(term);
    cout<<endl;
    sparseMatrix transpose[term[0].row*term[0].col];
    TransposeSparseMatrix(term, transpose);
    ExpandSparseMatrix(transpose);
    return 0;
}