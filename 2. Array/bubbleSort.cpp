#include <iostream>

using namespace std;
void swap(int &a, int &b) {
    b=a+b;
    a=b-a;
    b=b-a;
}

void bubbleSortA(int a[], int n){
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void bubbleSortD(int a[], int n){
    for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-i-1; j++) {
        if(a[j]<a[j+1]){
            swap(a[j], a[j+1]);
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
    bubbleSortA(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i];
    }
    return 0;
}
