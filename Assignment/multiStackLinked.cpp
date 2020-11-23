// C++ program to Implement a stack 
//using singly linked list 
#include <iostream> 
using namespace std; 

// Declare linked list node 

struct Node 
{ 
	int data; 
	struct Node* link; 
}; 

class Header
{
    public:
    int stackNumber;
    Node *top;
    Header *next;
    Header()
    {
        next = NULL;
    }

} *multiStack;

//struct Node* top; 

// Utility function to add an element 
// data in the stack insert at the beginning 
void push(int stackN, int data) 
{ 
	
	// Create new node temp and allocate memory 
	struct Node* temp; 
	temp = new Node();
    bool flag = false;
    Header *h = multiStack;
    if(multiStack == NULL)
    {
        multiStack = new Header;
        h = multiStack;
        h->stackNumber = 1;
        h->top = NULL;
    }
    else
    {
        while(h != NULL)
        {
            if(stackN == h->stackNumber){
                flag = true;
                break;
            }
                
            h = h->next;
        }
        if(flag == false && h->stackNumber == stackN-1)
        {
            h->next = new Header;
            h = h->next;
            h->stackNumber = stackN;
        }else if(flag == false) {
            cout<<"Stack not found"<<endl;
        }
    }
    
	// Check if stack (heap) is full. 
	// Then inserting an element would 
	// lead to stack overflow 
	if (!temp) 
	{ 
		cout << "\nHeap Overflow"; 
		exit(1); 
	} 

	// Initialize data into temp data field 
	temp->data = data; 

	// Put top pointer reference into temp link 
	temp->link = h->top; 

	// Make temp as top of Stack 
	h->top = temp; 
} 

// Utility function to pop top 
// element from the stack 
void pop(int stackN) 
{ 
	struct Node* temp; 
    bool flag = false;
    Header *h = multiStack;
    while(h != NULL)
    {
        if(stackN == h->stackNumber){
            flag = true;
            break;
        }
            
        h = h->next;
    }
    if(flag == false) {
        cout<<"Stack not found"<<endl;
    }

	// Check for stack underflow 
	if (h->top == NULL) 
	{ 
		cout << "\nStack Underflow" << endl; 
		exit(1); 
	} 
	else
	{ 
		
		// Top assign into temp 
		temp = h->top; 

		// Assign second node to top 
		h->top = h->top->link; 

		// Destroy connection between 
		// first and second 
		temp->link = NULL; 

		// Release memory of top node 
		delete temp; 
	} 
} 

// Function to print all the 
// elements of the stack 
void display(int stackN) 
{ 
	struct Node* temp; 
    bool flag = false;
    Header *h = multiStack;
    while(h != NULL)
    {
        if(stackN == h->stackNumber){
            flag = true;
            break;
        }
            
        h = h->next;
    }
    if(flag == false) {
        cout<<"Stack not found"<<endl;
    }

	// Check for stack underflow 
	if (h->top == NULL) 
	{ 
		cout << "\nStack Underflow"; 
		exit(1); 
	} 
	else
	{ 
		temp = h->top; 
		while (temp != NULL) 
		{ 

			// Print node data 
			cout << temp->data << "-> "; 

			// Assign temp link to temp 
			temp = temp->link; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	
	// Push the elements of stack 
	push(1, 11); 
	push(2, 22); 
	push(1, 33); 
	push(2, 44); 

	// Display stack elements 
	display(1);
    display(2);
    display(3); 

	// Delete top elements of stack 
	pop(1); 
	pop(2); 

	// Display stack elements 
	display(1);
    display(2); 
		
	return 0; 
} 