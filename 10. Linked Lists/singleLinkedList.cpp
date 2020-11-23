// Made by me
#include <iostream>

using namespace std;

class List
{
    public:
        int info;
        List *next;
        List()
        {
            next = NULL;
        }
} *head;

void insertBeg(int );
void insertEnd(int );
void insertPos(int , int);
void insertBefore(int, int);
void insertAfter(int, int);

List* searchList(int , bool);

void deleteB();
void deleteE();
void deletePos(int );
void deleteItem(int );
void deleteBefore(int );
void deleteAfter(int );

void displayBegToEnd();

void displayBegToEnd()
{
    if(head == NULL) {
        cout << "List is empty!!" << endl;
        return;
    }
    List *temp = head;
    while(temp != NULL)
    {
        cout<<temp->info<<" ";
        temp = temp->next;
    }   cout<<endl;
}

List* searchList(int ele, bool isAfter) {
    List *temp = head;
    List *prev = head;

    while(temp->next != NULL) {
        if(temp->info == ele) {
            if(isAfter)
                return temp;
            else 
                return prev;
        }
        prev = temp;
        temp = temp->next;
    }
    if(isAfter)
        return temp;
    else 
        return prev;
}

void insertBeg(int ele)
{
    List *temp = new List;
    temp->next = head;
    temp->info = ele;
    head = temp;
}

void insertEnd(int ele)
{
    List *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new List;
    temp->next->info = ele;
}

void insertPos(int pos, int ele)
{
    List *temp = head;
    bool flag = false;
    for(int i=1; temp != NULL; i++)
    {
        if(i == pos-1)
        {
            List *store = temp->next;
            temp->next = NULL;
            temp->next = new List;
            temp->next->info = ele;
            temp->next->next = store;
            flag = true;
            break;
        }
        temp = temp->next;
    }
    if(flag == false)
    {
        cout<<"Position not in List" << endl;
    }
}

void insertAfter(int query, int ele) {
    List *temp = head;
    temp = searchList(query, true);
    if(temp->info != query) {
        cout << "Query not found adding at the end" << endl;
        insertEnd(ele);
    }
    else {
        List *store = temp->next;
        temp->next = NULL;
        temp->next = new List;
        temp->next->info = ele;
        temp->next->next = store;
    }
}

void insertBefore(int query, int ele) {
    List *temp = head;
    temp = searchList(query, false);
    if(temp->next->info != query) {
        cout << "Query not found adding in the begining" << endl;
        insertBeg(ele);
    }
    else {
        List *store = temp->next;
        temp->next = NULL;
        temp->next = new List;
        temp->next->info = ele;
        temp->next->next = store;
    }
}

void deleteB() {
    List *temp = head;
    head = head->next;
    delete temp;
}

void deleteE() {
    List *temp = head;
    List *prev;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    } prev->next = NULL;
    delete temp;
}

void deletePos(int pos) {
    List *temp = head;
    List *prev = head;
    bool flag = false;
    for(int i=1; temp != NULL; i++)
    {
        if(i == pos)
        {
            List *store = temp->next;
            delete temp;
            prev->next = store;
            flag = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(flag == false)
    {
        cout<<"Position not in List" << endl;
    }
}

void deleteItem(int ele) {
    List *temp = head;
    temp = searchList(ele, false);
    if(temp->next->info == ele) {
        List *store = temp->next;
        temp->next = store->next;
        delete store;
    } else {
        cout << "Element not found" << endl;
    }
}

void deleteAfter(int ele) {
    List *temp = head;
    temp = searchList(ele, true);
    if(temp->next != NULL) {
        List *store = temp->next;
        temp->next = store->next;
        delete store;
    } else {
        cout << "Element not found" << endl;
    }
}

void deleteBefore(int ele) {
    List *temp = head;
    temp = searchList(ele, false);

    if(temp->next->info == ele) {
        List *store = temp;
        temp = searchList(temp->info, false);
        if(temp == head) {
            head = head->next;
        } else {
            temp->next = store->next;
        }
        delete store;
    } else {
        cout << "Element not found" << endl;
    }
}

int main()
{
    displayBegToEnd();
    insertBeg(1);
    insertBeg(2);
    displayBegToEnd();
    insertEnd(3);
    insertBeg(4);
    insertPos(4, 69);
    insertPos(69, 42);
    insertAfter(69, 12);
    insertAfter(42, 11);
    displayBegToEnd();
    insertBefore(12, 10);
    insertBefore(42, 9);
    displayBegToEnd();
    deleteB();
    deleteE();
    displayBegToEnd();
    deletePos(4);
    deletePos(10);
    displayBegToEnd();
    deleteItem(12);
    deleteItem(69);
    displayBegToEnd();
    deleteAfter(10);
    deleteAfter(3);
    displayBegToEnd();
    deleteBefore(2);
    deleteBefore(4);
    displayBegToEnd();
    return 0;
}