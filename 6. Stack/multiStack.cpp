#include <iostream>
#define MAX 100
#define BLOCK_SIZE 10

class multiStack {
    private:
        int s[MAX];
        int boundary[BLOCK_SIZE];
        int top[BLOCK_SIZE];
    public:
    // constructors, asssignment, destructor
        multiStack(int n) {
            for (int i = 0; i < n; ++i) {
                top[i] = boundary[i] = (MAX/n)*i - 1;
            }
        }
    void push(int i, int n) {
        if(top[i] == boundary[i+1] || top[i] == MAX-1) {
            std::cout << "Stack if full" << std::endl;
        } else {
            top[i]++;
            s[top[i]] = n;
            std::cout << "Entered at "<<i<<" = "<< n << std::endl;
        }
    }
    int pop(int i) {
        if(top[i] == boundary[i]) {
            std::cout << "Empty stack" << std::endl;
            return -1;
        }
        else {
            top[i]--;
            return s[top[i]+1];
        }
    }
    bool isEmpty(int i) {
        if(top[i] == boundary[i]) {
            return true;
        }
        else {
            return false; 
        }
    }
    int peek(int i) {
        if(top[i] == boundary[i]) {
            std::cout << "Empty stack" << std::endl;
            return -1;
        }
        else {
            return s[top[i]];
        }

    }
    void display(int i) {
        if(top[i]==boundary[i]) {
            std::cout << "Empty Stack" << std::endl;
        }
        else {
            for(int j=top[i]; j>boundary[i]; j--) {
                std::cout << "-->"<< s[j];
            } std::cout << std::endl;
        }
    }
};
int main()
{
    multiStack s(5);
    s.display(1);
    s.push(1, 0);
    s.push(1, 3);
    s.push(1, 4);
    s.push(1, 5);
    std::cout<<s.pop(1)<<std::endl;
   
    s.display(0);
    s.push(4, 0);
    s.push(0, 3);
    s.push(3, 4);
    s.push(4, 5);
    s.display(0);
    s.display(3);
    s.display(4);
    std::cout<<s.pop(0)<<std::endl;
    s.display(2);
    s.display(0);
    return 0;
}
