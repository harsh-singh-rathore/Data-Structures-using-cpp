#include <iostream>

using namespace std;

int binSearch(int a[], int n, int s) {
    int st=0, end=n-1;
    int mid;
    int flag=-1;

    do {

        mid=(st+end)/2;
        
        if(a[mid]==s) {
            return mid;
        }

        if(s<a[mid]) {
            end = mid-1;
        }

        else if(s>a[mid]){
            st = mid+1;
            cout<<"Inside Else if 2";
        }

    } while(s!=a[mid] && st<=end);
    if(s==a[mid]) {
        return mid;
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
    cout<<"Binary Search";
    int i = binSearch(a, n, s);
    cout<<"wow";
    cout <<"ans"<< i;
    return 0;
}
