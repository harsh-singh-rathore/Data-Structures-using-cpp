#include<iostream>
#define MAX 100
using namespace std;

class stack
{
    private:
        int s[MAX];
        int top;
    public:
        stack() {
            top = -1;
        }
        void push(int n) {
            if(top == MAX-1)
                cout<<"Stack Overflow";
            s[++top]=n;
        }
        int pop() {
            if(top == -1) {
                cout<<"Stack Underflow";
                return -1;
            }
            else {
                top--;
                return s[top+1];
            }
        }
        int peek() {
            if(top == -1) {
                cout<<"Empty Stack";
                return -1;
            }
            else {
                return s[top];
            }
        }
        bool isEmpty() {
            if(top < 0) {
                return true;
            }
            else {
                return false;
            }
        }
        void display() {
            if(top == -1) {
                cout << "Stack Empty";
            }
            else {
                for(int i=top; i>=0; i--) {
                    cout << "-->" << s[i] ;
                } cout << endl;
            }
        }
};

int main() {
    stack s;
    cout<<s.isEmpty()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    s.display();
    return 0;
}

