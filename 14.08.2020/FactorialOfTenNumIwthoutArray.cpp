#include <iostream>

using namespace std;

int main() {
    int n;
    for(int i = 0; i<10; i++) {
        cin>>n;
        int fact = 1;
        for(int j = n; j>0; j--) {
            fact*=j;
        }
        cout<<"factorial "<<n<<" = "<<fact;
    }
}
