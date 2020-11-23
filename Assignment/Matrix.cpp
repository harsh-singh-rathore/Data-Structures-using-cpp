#include<iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertSortA(int a[][20], int m, int n) {
    for(int k=0; k<m; k++){
        for(int i=1; i<n; i++){
            for(int j=i; j>0; j--) {
                if(a[k][j-1]>a[k][j]) {
                    swap(a[k][j], a[k][j-1]);
                }
            }
        }
    }    
}

void display(int MAT[][20], int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<MAT[i][j]<<" ";
        }cout<<endl;
    }
}

int main()
{
    int MAT[20][20];
    int m, n;
    cout<<"Enter rows:";
    cin>>m;
    cout<<"Enter Columns:";
    cin>>n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<"Enter Element "<<i<<" "<<j<<" :";
            cin>>MAT[i][j];
        }
    }

    display(MAT, m, n);

    cout<<"Row wise Sorted Matrix"<<endl;

    insertSortA(MAT, m, n);

    display(MAT, m, n);
    
    return 0;
}