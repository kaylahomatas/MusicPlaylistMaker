#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <string>

// Declaring a template for class Node with data type T
template <typename T>
class Node;

//Declaring a template for class SinglyLinkedList with data type T
template <typename T>
class SinglyLinkedList;

// class Node: stores data for each node to be used in a linked list
// Private members: an element of type T, and a pointer to the next node. Also declares the class for the linked list as a friend
// Public members: a getter function for the pointer to the next node and a getter function for the element of the node
template <typename T>
class Node {
private:
    T elem;
    Node<T>* next;
    friend class SinglyLinkedList<T>;
public:
    Node<T>* getNext() const;
    T getElem() const;
};

// class SinglyLinkedList: stores a list of nodes connected by pointers to the node in front of it
// Private members: a pointer to the node at the head of the list and a variable to hold how many nodes are in the list
// Public members: a constructor, destructor, setters, getters, and other functions to add and remove nodes
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    int size_list;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void setSizeList(int size);
    int getSizeList() const;
    bool isListEmpty() const; 
    const T& firstElem() const; 
    void addFront(const T& e);  
    void removeFront();  
    Node<T>* getHead() const;
    T getNthElem(Node<T>* head, int i);
    int countNodes() const;
    void deleteNthNode(Node<T>* head, int pos);
};

// Template for constructor to initialize a linked list
// Sets the head of the list to point to NULL and the size of the list to be zero
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    Node<T>* head = NULL;
    size_list = 0;
}

// Template for destructor to destroy a linked list
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (!isListEmpty()) {
        removeFront(); // deletes nodes until the list is empty
    }
}

// Template for setter function for the size of the list
template <typename T>
void SinglyLinkedList<T>::setSizeList(int size) {
    size_list = size;
}

// Template for getter function for the size of the list
template <typename T>
int SinglyLinkedList<T>::getSizeList() const {
    return size_list;
}

// Template for function to determine if the list is empty or not. 
// Returns a boolean value: true if the list empty, false if not
template <typename T>
bool SinglyLinkedList<T>::isListEmpty() const {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Template for function to return the element of the first node in the list
template <typename T>
const T& SinglyLinkedList<T>::firstElem() const {
    return head->elem;
}

// Template for function to add a new node to the front of the list
// Takes an argument of a reference to the element that will be stored in the node
template <typename T>
void SinglyLinkedList<T>::addFront(const T& e) {
    Node<T>* temp = new Node<T>; // creating the new node
    temp->elem = e; // storing given element value
    temp->next = head; // making the node the head of the list
    head = temp;
    size_list++; // incrementing the size of the list by one
}

// Template for function to remove the node at the front of the list
template <typename T>
void SinglyLinkedList<T>::removeFront() {
    Node<T>* temp = head; // creating a temporary node to point to the head of the list
    head = temp->next; // removing the node
    delete temp; // deallocating the memory for the deleted node
    size_list--; // decrementing the size of the list by one
}

// Template for getter function for a pointer to the head of the list
template <typename T>
Node<T>* SinglyLinkedList<T>::getHead() const {
    return head;
}

// Template for function to get the element of a node at a given position
// Returns element of data type T
template <typename T>
T SinglyLinkedList<T>::getNthElem(Node<T>* head, int pos) {

    Node<T>* cur_node = head;   // creating a temporary node to point to the head of the list
    int count = 0;

    while (cur_node != NULL) {    // Iterating through the nodes of the list
        if (count == pos) {         
            return cur_node->elem;  // Once at given position in the list, returns the node's element
        }
        count++;
        cur_node = cur_node->next;
    }

    return head->elem;  // if no element found at given position, returns the element of the first node
}

// Template for function to count and return the number of nodes in the list 
template <typename T>
int SinglyLinkedList<T>::countNodes() const {
    Node<T>* temp = head;   // creating a temporary node to point to the head of the list
    int count = 0;

    while (temp != NULL) {  // while temp has not reached the end of the list, count the nodes
        count++;
        temp = temp->next;
    }

    return count;
}

// Template for function to delete a node at a given position
template <typename T>
void SinglyLinkedList<T>::deleteNthNode(Node<T>* head, int pos) {
    
    int i;

    if (pos == size_list - 1) { // first checking if the position of the node to be deleted is the last node of the list
        if (pos == 0) { // further checking if the node is the only node in the list
            Node<T>* temp = head;
            head = NULL; // removing the only node, the list will be empty
            delete temp;
            size_list--;
            return;
        }
        Node<T>* temp = head; // if the node to be deleted is the last node of the list:
        for (i = 0; i < pos - 1; i++) {   // iterating through the list until we find the node before the node to be deleted
            temp = temp->next;
        }

        Node<T>* del = temp->next;  // temp points to node before node to be deleted, creating a temporary node to point to node to be deleted
        temp->next = NULL;  // removing last node of the list by having the node before it point to NULL
        delete del;
        size_list--;
    }
    else if (pos == 0) { // if node to be deleted is the first node in the list with other nodes
        
        removeFront(); // call class function to remove the node at the front of the list

    }
    else {      // if node to be deleted is somewhere else in the list

        Node<T>* temp = head;   // creating temporary node to point to head of the list
        for (i = 0; i < pos - 1; i++) {   // iterating through list until temp points to node before node to be deleted
            temp = temp->next;
        }

        Node<T>* node_del = temp->next;     // creating node to point to node to be deleted
        temp->next = node_del->next;    // removing node to be deleted by having previous node point to the node after it
        delete node_del;
        size_list--;

    }

}

#endif