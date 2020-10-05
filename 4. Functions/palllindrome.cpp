#include <iostream>

using namespace std;

bool isPallindrome(int n) {
    int p;
    int nc=n;
    do {
        p=p*10 + n%10;
        n=n/10;
    }while(n>0);
    if (nc == p)
        return true;
    else 
        return false;
}

int main() {
    int n; cin>>n;
    cout<<isPallindrome(n);
}