#include <iostream>

using namespace std;

class LinkedList {
    public:
    class List
    {
        public:
            List *next;
            List()
            {
                next = NULL;
            }
            void putElement(int ele) {
                info = ele;
            }
            int getElement() {
                return info;
            }
        private:
            int info;
    };
    LinkedList() {
        head = NULL;
    }
    // Class functions
    void insertBeg(int );
    void insertEnd(int );
    void insertPos(int , int);
    void insertBefore(int, int);
    void insertAfter(int, int);

    
    List* searchList(int ele, bool isAfter) {
        List *temp = head;
        List *prev = head;

        while(temp->next != NULL) {
            if(temp->getElement() == ele) {
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

    void deleteB();
    void deleteE();
    void deletePos(int );
    void deleteItem(int );
    void deleteBefore(int );
    void deleteAfter(int );

    void displayBegToEnd();

    private:
    List *head;
    
};

void LinkedList :: displayBegToEnd()
{
    if(head == NULL) {
        cout << "List is empty!!" << endl;
        return;
    }
    List *temp = head;
    while(temp != NULL)
    {
        cout<<temp->getElement()<<" ";
        temp = temp->next;
    }   cout<<endl;
}

void LinkedList :: insertBeg(int ele)
{
    List *temp = new List;
    temp->next = head;
    temp->putElement(ele);
    head = temp;
}

void LinkedList :: insertEnd(int ele)
{
    List *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new List;
    temp->next->putElement(ele);
}

void LinkedList :: insertPos(int pos, int ele)
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
            temp->next->putElement(ele);
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

void LinkedList :: insertAfter(int query, int ele) {
    List *temp = head;
    temp = searchList(query, true);
    if(temp->getElement() != query) {
        cout << "Query not found adding at the end" << endl;
        insertEnd(ele);
    }
    else {
        List *store = temp->next;
        temp->next = NULL;
        temp->next = new List;
        temp->next->putElement(ele);
        temp->next->next = store;
    }
}

void LinkedList :: insertBefore(int query, int ele) {
    List *temp = head;
    temp = searchList(query, false);
    if(temp->next->getElement() != query) {
        cout << "Query not found adding in the begining" << endl;
        insertBeg(ele);
    }
    else {
        List *store = temp->next;
        temp->next = NULL;
        temp->next = new List;
        temp->next->putElement(ele);
        temp->next->next = store;
    }
}

void LinkedList :: deleteB() {
    List *temp = head;
    head = head->next;
    delete temp;
}

void LinkedList :: deleteE() {
    List *temp = head;
    List *prev;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    } prev->next = NULL;
    delete temp;
}

void LinkedList :: deletePos(int pos) {
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

void LinkedList :: deleteItem(int ele) {
    List *temp = head;
    temp = searchList(ele, false);
    if(temp->next->getElement() == ele) {
        List *store = temp->next;
        temp->next = store->next;
        delete store;
    } else {
        cout << "Element not found" << endl;
    }
}

void LinkedList :: deleteAfter(int ele) {
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

void LinkedList :: deleteBefore(int ele) {
    List *temp = head;
    temp = searchList(ele, false);

    if(temp->next->getElement() == ele) {
        List *store = temp;
        temp = searchList(temp->getElement(), false);
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


int main() {
    LinkedList demo;
    demo.displayBegToEnd();
    demo.insertBeg(1);
    demo.insertBeg(2);
    demo.displayBegToEnd();
    demo.insertEnd(3);
    demo.insertBeg(4);
    demo.insertPos(4, 69);
    demo.insertPos(69, 42);
    demo.insertAfter(69, 12);
    demo.insertAfter(42, 11);
    demo.displayBegToEnd();
    demo.insertBefore(12, 10);
    demo.insertBefore(42, 9);
    demo.displayBegToEnd();
    demo.deleteB();
    demo.deleteE();
    demo.displayBegToEnd();
    demo.deletePos(4);
    demo.deletePos(10);
    demo.displayBegToEnd();
    demo.deleteItem(12);
    demo.deleteItem(69);
    demo.displayBegToEnd();
    demo.deleteAfter(10);
    demo.deleteAfter(3);
    demo.displayBegToEnd();
    demo.deleteBefore(2);
    demo.deleteBefore(4);
    demo.displayBegToEnd();
    return 0;
}