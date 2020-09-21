#include<iostream>
#include<math.h>

using namespace std;

int main() {

    int num;
    cin>>num;
    bool flag=true;
    for(int i =2; i<sqrt(num); i++) {
        if (num == 2){
            flag = true;
        }
        else if(num%i == 0) {
            flag = false;
        }
    }
    if(num == 0 || num == 1)
        flag = false;
    if(flag == true){
        cout<<"The number is prime";
    }
    else
        cout<<"The number is not prime";

}
