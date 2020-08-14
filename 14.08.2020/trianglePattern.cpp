#include <iostream>

using namespace std;

int main() {
    int noOfRows;
    cin>>noOfRows;
    int num = 1;
    for(int i=0; i<noOfRows; i++) {
        for(int j = 0; j<i+1; j++) {
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

