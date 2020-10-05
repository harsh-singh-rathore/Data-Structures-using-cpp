#include<iostream>

int reverseN(int n) {
    int revn=0;
    while(n!=0) {
        revn=revn*10 + n%10;
        n/=10;
    }
    return revn;
}

int main() {
    int n; std::cin>>n;
    std::cout<<reverseN(n);
    return 0;
}
