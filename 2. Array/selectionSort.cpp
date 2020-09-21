#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int n;
    n = a;
    a = b;
    b = n;
}

void selectSortA(int a[], int n) {
    int sm;
    for(int i=0; i<n-1; i++) {
        sm=i;
        for(int j=i+1; j<n; j++) {
            if(a[sm]>a[j]) {
                sm=j;
            }
        } swap(a[i], a[sm]);
    }
}

void selectSortD(int a[], int n) {
    int sm;
    for(int i=0; i<n-1; i++) {
        sm=i;
        for(int j=i+1; j<n; j++) {
            if(a[sm]<a[j]) {
                sm=j;
            }
        } swap(a[i], a[sm]);
    }
}


int main() {
    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    selectSortA(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i];
    }

    return 0;
}
