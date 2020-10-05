#include<iostream>

int factorialRec(int n){
    if(n==1 || n==0)
        return 1;
    else if(n>1)
        return(n*factorialRec(n-1));
    else
        return -1;
}

int factorialIter(int n) {
    if(n==0)
        return 1;
    else if(n<0) 
        return -1;
    else {
        int fact = 1;
        for(int i=1; i<=n; i++) {
            fact*=i;
        }
        return fact;
    }
}

int main() 
{
    std::cout<<factorialRec(3)<<"\n"<<factorialIter(3);
    return 0;
}

