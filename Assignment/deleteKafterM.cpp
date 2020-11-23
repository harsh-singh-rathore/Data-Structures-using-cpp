// CPP Program to implement self-organizing list 
// using move to front method 
#include <iostream> 
using namespace std; 

// structure for self organizing list 
struct self_list { 
	int value; 
	struct self_list* next; 
}; 

// head and rear pointing to start and end of list resp. 
self_list *head = NULL, *rear = NULL; 

// function to insert an element 
void insert_self_list(int number) 
{ 
	// creating a node 
	self_list* temp = (self_list*)malloc(sizeof(self_list)); 

	// assigning value to the created node; 
	temp->value = number; 
	temp->next = NULL; 

	// first element of list 
	if (head == NULL) 
		head = rear = temp; 

	// rest elements of list 
	else { 
		rear->next = temp; 
		rear = temp; 
	} 
} 

// function to search the key in list 
// and re-arrange self-organizing list 
bool search_self_list(int key) 
{ 
	// pointer to current node 
	self_list* current = head; 

	// pointer to previous node 
	self_list* prev = NULL; 

	// searching for the key 
	while (current != NULL) { 

		// if key found 
		if (current->value == key) { 

			// if key is not the first element 
			if (prev != NULL) { 

				/* re-arranging the elements */
				prev->next = current->next; 
				current->next = head; 
				head = current; 
			} 
			return true; 
		} 
		prev = current; 
		current = current->next; 
	} 

	// key not found 
	return false; 
} 

// function to display the list 
void display() 
{ 
	if (head == NULL) { 
		cout << "List is empty" << endl; 
		return; 
	} 

	// temporary pointer pointing to head 
	self_list* temp = head; 
	cout << "List: "; 

	// sequentially displaying nodes 
	while (temp != NULL) { 
		cout << temp->value; 
		if (temp->next != NULL) 
			cout << " --> "; 

		// incrementing node pointer. 
		temp = temp->next; 
	} 
	cout << endl << endl; 
} 

// Driver Code 
int main() 
{ 
	/* inserting five values */
	insert_self_list(1); 
	insert_self_list(2); 
	insert_self_list(3); 
	insert_self_list(4); 
	insert_self_list(5); 

	// Display the list 
	display(); 

	// search 4 and if found then re-arrange 
	if (search_self_list(4)) 
		cout << "Searched: 4" << endl; 
	else
		cout << "Not Found: 4" << endl; 

	// Display the list 
	display(); 

	// search 2 and if found then re-arrange 
	if (search_self_list(2)) 
		cout << "Searched: 2" << endl; 
	else
		cout << "Not Found: 2" << endl; 
	display(); 

	return 0; 
} 
