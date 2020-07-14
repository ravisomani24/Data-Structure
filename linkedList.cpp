#include <bits/stdc++.h>
using namespace std;

//First is to create a linked list node
typedef struct Node {
    int data;
    Node* next;
}Node;

Node* head = NULL; // Head pointer initially points to null
int lengthOfLinkedList = 0; // To calculate the length of linked list. This will be helpful for inserting at any position cases and also for
//traversing.
//Whenever we create a node for inserting, increment length.


// For inserting a node at any place first we have to create a node. The node which is created will contain data and will point nowhere
Node* createNode(int d) {

    Node* nodePtr = new Node;
    nodePtr->data = d;
    nodePtr->next = NULL;
    lengthOfLinkedList++;
    return nodePtr;

}


//Insert operation in linked list-:


//1. At the beginning -: First create a node with the data. Then store the current address of head in the created node next field and
// then point the head to the created node's address.
void insertAtBeginning(int data) {

    Node* nodePointer = createNode(data);
    nodePointer->next = head;
    head = nodePointer;

}

//2.At end-: If the list is empty it is same as insertAtBeginning but if its not empty then traverse upto end of list and when you reach at
// the last node in list, point its next field to new created node
void insertAtEnd(int data) {

    Node* nodePointer = createNode(data);
    Node* temp = head;
    if(head == NULL) {
        
        nodePointer->next = head;
        head = nodePointer;

    } else {

        while(temp->next != NULL)
            temp = temp->next;

        nodePointer->next = temp->next;
        temp->next = nodePointer;

    }

}

//3.At any position
void insertAtAnyPosition(int data, int position) {

    Node* temp = head;
    Node* nodePtr = createNode(data);
    if(position == 1) 
        insertAtBeginning(data);
    else if(position == lengthOfLinkedList)
        insertAtEnd(data);
    else if(position < lengthOfLinkedList) {

        for(int i = 0; i < position - 2; i++)
                temp = temp->next;

        nodePtr->next = temp->next;
        temp->next = nodePtr;

    } else {
        cout << "Enter position less than the length of list\n";
    }

}

//Delete operation of the linked list


//1.Delete first node
void deleteFirstNode() {

    Node* temp = head;
    if(head == NULL)
        cout << "There is nothing in list to delete.\n";
    else {

        head = temp->next;
        delete(temp);
        lengthOfLinkedList--;

    }
    
}


//2. Delete last node
void deleteLastNode() {

    Node* traversePtr = head;
    
    if(head == NULL)
        cout << "There is nothing to delete.\n";

    else if(head->next == NULL) {
        deleteFirstNode();
    }
        
    else {

        Node* deleteNodePtr = traversePtr->next;
        while(deleteNodePtr->next != NULL) {

            traversePtr = traversePtr->next;
            deleteNodePtr = deleteNodePtr->next;

        }   
        
        lengthOfLinkedList--;
        traversePtr->next = deleteNodePtr->next;
        delete(deleteNodePtr);

    }

}


//3. Delete any position node
void deleteNodeOfAnyPosition(int pos) {

    if(pos == lengthOfLinkedList)
        deleteLastNode();

    else if(pos == 1)
        deleteFirstNode();

    else if(pos < lengthOfLinkedList) {

        Node* traversePtr, *deleteNodePtr;
        traversePtr = head;
        deleteNodePtr = traversePtr->next;
        lengthOfLinkedList--;
    
        for(int i = 0; i < pos - 2; i++) {

            traversePtr = traversePtr->next;
            deleteNodePtr = deleteNodePtr->next;
        
        }

        traversePtr->next = deleteNodePtr->next;
        delete(deleteNodePtr);

    }

    else {
        cout << "Enter the position less than length of list.\n";
    }
    
}

//4.Search by value in linkedlist

int searchValueInList(int searchValue) {

    int flag = 0;
    int positionOfSearchedValue = 1;
    Node* traversePtr = head;

    while(traversePtr != NULL) {

        if(searchValue == traversePtr->data) {
            
            flag = 1;
            break;

        } else {

            positionOfSearchedValue++;
            traversePtr = traversePtr->next;

        }

    }

    if(flag == 0)
        return -1;
    else
        return positionOfSearchedValue;

}

//Reverse a Linked List
void reverseLinkedList() {



}


//Middle of Linked List
void middleOfLinkedList() {



}

void display() {

    Node* traversePtr = head;
    if(head == NULL)
        cout << "The List is Empty!" << endl;
    else {

        cout << "The length of the list is: " << lengthOfLinkedList << endl;
        while(traversePtr != NULL) {

            cout << traversePtr->data << "  ";
            traversePtr = traversePtr->next;

        }

        cout << endl;

    }

}


int main()
{

    cout << "Welcome to the Linked List Programs implemented by Ravi Somani\n";
    while(true) {

        int optionSelectedByUser, data, pos, location, valueToFind, valueToDelete;
        char ans;
        cout << "Which operation would you like to perform?\n1.Insert value at beginning.\n2.Insert value at end.\n3.Insert value at any position.\n";
        cout << "4.Delete first node from list.\n5.Delete last node from the list.\n6.Delete node of any position.\n7.Search value in the list.\n";
        cout << "8.Exit\n";
        cin >> optionSelectedByUser;

        if(optionSelectedByUser > 7)
            break;
        switch (optionSelectedByUser)
        {
        case 1:
            cout << "Enter value to be inserted at the beginning: ";
            cin >> data;
            insertAtBeginning(data);
            display();
            break;
        
        case 2:
            cout << "Enter value to be inserted at the end: ";
            cin >> data;
            insertAtEnd(data);
            display();
            break;

        case 3:
            cout << "Enter value to be inserted: ";
            cin >> data;
            cout << endl;
            cout << "Enter position at which you have to insert the value: ";
            cin >> pos;
            insertAtAnyPosition(data, pos);
            display();
            break;

        case 4:
            cout << "The first node is deleted.\n";
            deleteFirstNode();
            display();
            break;

        case 5:
            cout << "The last node is deleted.\n";
            deleteLastNode();
            display();
            break;

        case 6:
            cout << "Enter the position of node to be deleted: ";
            cin >> pos;
            deleteNodeOfAnyPosition(pos);
            display();
            break;

        case 7:
            cout << "Enter the value to be searched: ";
            cin >> valueToFind;
            location = searchValueInList(valueToFind);

            if(location == -1)
                cout << "The value " << valueToFind << " is not present in the list.\n";
            else
                cout << "The value " << valueToFind << " is at position " << location << " in the list.\n";
            break;

        }

    }

}