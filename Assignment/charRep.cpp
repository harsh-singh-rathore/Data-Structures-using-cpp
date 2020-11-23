#include <iostream>
using namespace std;

int main()
{
    char str[100], t;
    int i, characters[255] = {0}, ch;
    cin.getline(str, 100);
    cout << "List of duplicate characters in String '";
    for(i=0; str[i]!='\0'; i++){
        ch = str[i];
        characters[ch]++;
        cout<<str[i];
    }
    cout<<"'";
    for(i=0; i<255; i++){
        if(characters[i] >= 2){
            t = i;
            cout<<" "<<t<<" : "<<characters[i];
        }
    }
    return 0;
}