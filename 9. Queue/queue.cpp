#include <iostream> 
#define MAX 100
using namespace std; 
  
// A structure to represent a queue 
class queue { 
    private:
        int front, rear, size; 
        int q[MAX]; 
    public:
        queue() {
            front=rear=-1;
        }
        bool isEmpty() {
            return front==-1 && rear==-1;
        }
        bool isFull() {
            return rear==MAX-1;
        }
        void enqueue(int i);
        int dequeue() {
            if(isEmpty()) {
                cout<<"Queue is empty";
                return -1;
            } else if(front == rear) {
                int temp = q[rear];
                front = rear = -1;
                return temp;
            } else {
                front++;
                return q[front-1];
            }
        }
        void display() {
            if(isEmpty()) {
                cout<<"Queue is empty";
                return;
            }
            for(int i=front; i<=rear; i++){
                 cout<<q[i]<<" ";
            } cout<<endl;
        }
}; 
 

void queue::enqueue(int i)
{
    if(isFull()) {
        cout<<"Queue is full";
        return; 
    } else if(isEmpty()) {
        front = 0;
    }
    q[++rear] = i;
}
  
// Driver code 
int main() 
{ 
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.display();
    q.enqueue(4);

    cout<<"Dequeued"<<q.dequeue()<<endl;
    q.display();
    return 0; 
} 
  
