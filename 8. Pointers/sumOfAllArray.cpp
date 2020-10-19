#include<iostream>

using namespace std;

int main() 
{
    int a[] = {1, 2, 3, 4};
    int sum(0), *ptr=a;

    for(int i=0; i<4; i++)
    {
        sum+=*ptr;
        ptr++;
    }

}