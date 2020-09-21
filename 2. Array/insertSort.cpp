#include<iostream>

using namespace std;

void swap(int &a, int &b) {
    int n;
    n = a;
    a = b;
    b = n;
}

void insertSortA(int a[], int n) {
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--) {
            if(a[j-1]>a[j]) {
                swap(a[j], a[j-1]);
            }
        }
    }    
}

void insertSortD(int a[], int n) {
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--) {
            if(a[j-1]<a[j]) {
                swap(a[j], a[j-1]);
            }
        }
    }    
}

int main() {
    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    insertSortA(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i];
    }
    return 0;
}   
