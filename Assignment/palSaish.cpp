#include <iostream>

using namespace std;

void reverse_num(int num)
{    
    int rem;

    // base condition
    if (num == 0)
    {
        return;
    }

    else
    {
        rem = num % 10; // get the rightmost digit
        cout<<rem;
        reverse_num(num/10);  // recursive call
    }

}

void pallindrome(int a, int t){
    if(a == 0)
    {
      reverse_num(t);  
    }
    else
    {
        cout<< a;
        t = t*10 + a;
        a--;
        pallindrome(a,t);
    }
}

int main()
{
    int a,c;
    int base = 0;
    cin>> a;
    pallindrome(a,base);
}