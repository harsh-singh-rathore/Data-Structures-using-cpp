#include<iostream>
#define MAX 100
using namespace std;

class stack
{
    private:
        int s[MAX];
        int top1;
        int top2;
    public:
        stack() {
            top1 = -1;
            top2 = MAX;
        }
        void push(int stackN, int n) {
            if(stackN == 1) {
               if(top1 == MAX || top1 == top2-1)
                cout<<"Stack Overflow"<< endl;
            s[++top1]=n;
            }
            else if(stackN == 2) {
                if(top2 == 0 || top2 == top1+1)
                    cout<<"Stack Overflow" << endl;
                s[--top2]=n;
            }      
        }
        int pop(int stackN) {
            if(stackN == 1) {
                if(top1 == -1) {
                    cout<<"Stack Underflow"<< endl;
                    return -1;
                }
                else {
                    top1--;
                    return s[top1+1];
                }
            } else if(stackN == 2) {
                if(top2 == MAX) {
                    cout<<"Stack Underflow";
                    return -1;
                }
                else {
                    top2++;
                    return s[top2-1];
                }
            }
            
        }
        int peek(int stackN) {
            if (stackN == 1) {
                if(top1 == -1) {
                    cout<<"Empty Stack" << endl;
                    return -1;
                }
                else {
                    return s[top1];
                }
            }
            else if(stackN == 2) {
                if(top2 == MAX) {
                    cout<<"Empty Stack";
                    return -1;
                }
                else {
                    return s[top2];
                }
            }
        }
        bool isEmpty(int stackN) {
            if(stackN == 1){
                if(top1 < 0) {
                    return true;
                }
                else {
                    return false;
                }
            } else if(stackN == 2) {
                if(top2 > MAX) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        void display() {
            if(top1 == -1) {
                cout << "Stack1 Empty";
            }
            else {
                cout << "Stack1" << endl;
                for(int i=top1; i>=0; i--) {
                    cout << "-->" << s[i] ;
                } cout << endl;
            }
            if(top2 == MAX) {
                cout << "Stack2 Empty";
            } else {
                cout << "Stack2";
                for(int i=top2; i<MAX; i++) {
                    cout << "-->" << s[i] ;
                } cout << endl;
            }
        }
};

int main() {
    stack s;
    cout<<s.isEmpty(1)<<endl;

    s.push(2, 1);
    s.push(2, 2);
    s.push(2, 3);
    s.push(2, 4);
    s.push(2, 5);
    s.display();
    cout<<s.pop(1)<<endl;
    cout<<s.pop(2)<<endl;
    cout<<s.peek(1)<<endl;
    s.display();
    return 0;
}