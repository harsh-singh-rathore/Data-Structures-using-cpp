#include<iostream>

using namespace std;

int main() {
    int sum(0);
    int n;
    cin>>n;
    do
    {
        sum+=n;
        cin>>n;
    }while(n!=-1);
    cout<<"Sum is "<<sum;
}
