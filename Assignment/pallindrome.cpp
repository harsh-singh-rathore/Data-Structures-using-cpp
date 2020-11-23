#include <iostream>
using namespace std;
void palindrome(int a,int m,bool flag){
    cout<<a;
    if(a>1&&flag==true){
        palindrome(a-1,m,true);
    }
    else if(a==1&&flag==true){
        cout<<a;
        palindrome(a+1,m,false);
    }
    else if(a>1&&flag==false&&a<m){
        palindrome(a+1,m,false);
    }

}
int main()
{
   palindrome(5,5,true);
}