#include <iostream>

using namespace std;

int binSearch(int a[], int n, int s) {
    int st=0, en=n-1;
    int mid;
    int flag=-1;

    while(st <= en) {

        mid=(st+en)/2;

        if(a[mid]==s) {
            return mid;
        }

        if(a[mid]<s) {
            st = mid+1;
        }

        else {
            en = mid-1;
        }

    }
    return -1;
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int s; cin>>s;
    int i = binSearch(a, n, s);
    cout <<"\nans : "<< i;
    return 0;
}