#include <iostream>

using namespace std;

int linSearch(int a[], int n, int s) {
    int flag = -1;
    for(int i=0; i<n; i++) {
        if(a[i]==s) {
            return i;
        }
    }
    return flag;
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int s; cin>>s;
    int i = linSearch(a, n, s);
    cout << i;
    return 0;
}
