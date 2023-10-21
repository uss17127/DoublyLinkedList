#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

/*
  Constructor - sets head and tail, sets length to 0
*/
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

/*
  Destructor - destructs items, deletes items
*/
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    NodeType<T> *ptr;
    while(this->head!=NULL) {
        ptr = this->head;
        this->head = this->head->next;
        delete ptr;
    }
}

/*
  Item is inserted into the list, maintaining sorted order
*/
template<class T>
void DoublyLinkedList<T>::insertItem(T &item) {
    NodeType<T> *node = new NodeType<T>;
    node->data = item;
    node->next = NULL;
    node->back = NULL;
    // If list is empty
    if(this->head == NULL) {
        this->head = node;
        this->tail = node;
        //ADD POINTERS

    }
    // If item needs to be added at the beginning
    else if (item < this->head->data) {
        node->next = this->head;
        this->head->back = node;
        this->head = node;
    }
    //If item needs to be added at the end
    else if (item > this->tail->data) {
        this->tail->next = node;
        node->back = this->tail;
        this->tail = node;
    }
    //General
    else {
        NodeType<T> *temp = this->head;
        while (temp != NULL && temp->data < item) {
            temp = temp -> next;
        }
        NodeType<T> *temp2 = temp->back;
        temp2->next = node;
        node->back = temp2;
        node->next = temp;
        temp->back = node;
    }
    this->length++;
}

/*
  Removes user-specified node from list, and if item is not present in th
  list, prints out message to user.
*/
template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
    NodeType<T> *temp = this->head;
    if (this->length == 0) {
        cout << "You cannot delete from an empty list." << endl;
        return;
    }
    while (temp != NULL) {
        if(temp->data == item) {
            break;
        }
        temp=temp->next;
    }
    //delete item
    if(temp != NULL) {
        //Delete head
        if (temp->back == NULL && temp->next != NULL) {
            this->head = this->head->next;
            this->head->back = NULL;
            delete temp;
        }
        //Delete tail
        else if (temp->next == NULL && temp->back != NULL) {
            this->tail = this->tail->back;
            this->tail->next = NULL;
            delete temp;
        }
        //Delete only item
        else if (temp->next == NULL && temp->back == NULL) {
            this->head = NULL;
            this->tail = NULL;
            delete temp;
        }
        //General Case
        else {
            NodeType<T> *node, *node2;
            node = temp->back;
            node2 = temp->next;
            node->next = node2;
            node2->back = node;
            delete temp;
        }
        length--;
    } else {
        cout << "Item not in list!" << endl;
    }
}

/*
  Returns length of list
*/
template<class T>
int DoublyLinkedList<T>::lengthIs() const {
    return this->length;
}

/*
  Print nodes in list
*/
template<class T>
void DoublyLinkedList<T>::print() {
    NodeType<T> *temp = this->head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "" << endl;
}

/*
  Prints list in reverse order (greatest to least)
*/
template<class T>
void DoublyLinkedList<T>::printReverse() {
    NodeType<T> *temp = this->tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->back;
    }
    cout << "" << endl;
}

/*
  Takes input from the user for the lower and upper bound (both inclusive)
  for a range of value that you will delete from the list
*/
template<class T>
void DoublyLinkedList<T>::deleteSubsection(T &item1, T &item2) {
    NodeType<T> *temp;
    //Head is null so list is empty
    if (this->head == NULL) {
        return;
    }
    //Items out of range
    if (this->tail->data < item1) {
        return;
    }
    //Items out of range
    if (this->head->data > item2) {
        return;
    }
    temp = this->head;
    while(temp != NULL && temp->next == NULL) {
        temp = temp->next;
    }

    if (temp != NULL) {
        if(temp->back == NULL && temp->next != NULL) {
            this->head = this->head->next;
            this->head->back = NULL;
            delete temp;
            deleteSubsection(item1, item2);
        } else if(temp->next == NULL && temp->back != NULL) {
            this->tail = this->tail->back;
            this->tail->next = NULL;
            delete temp;
        } else if (temp->back == NULL && temp->next == NULL) {
            this->head = NULL;
            this->tail = NULL;
            delete temp;

        }
        //General
        else {

            NodeType<T> *temp2 = this->tail;
            while(temp2!= NULL && temp2->data>item2){
                temp2 = temp2->back;
            }
            if(temp2->next == temp){
                return;
            }
            else{
                temp->back->next = temp2->next;
                if(temp2->next!=NULL){
                    temp2->next->back = temp->back;
                }
                NodeType <T> *temp3;
                while(temp != temp2){
                    temp3 = temp2;
                    temp = temp->next;
                    delete temp3;
                }
                delete temp;
            }
            return;
        }
    }

}

/*
  Returns the value that occurs the most in the list.
*/
template<class T>
T DoublyLinkedList<T>::mode() {
    T mode = 0;
    T before;
    int count = 0;
    int most = 0;
    if (this->head == NULL) {
        return mode;
    }

    NodeType<T> *temp = this->head->next;
    mode = this->head->data;
    before = this->head->data;
    count++;
    most++;

    while (temp != NULL) {
        if (temp->data == temp->back->data) {
            count++;
        } else {
            if (count>most) {
                most = count;
                count = 1;
                mode = before;
            }
        }
        before = temp->data;
        temp = temp->next;
    }
    return mode;
}

/*
  Swaps every other node in the list.
*/
template<class T>
void DoublyLinkedList<T>::swapAlternate() {
    // List is empty
    if (this->head == NULL) {
        return;
    }
    // Not enough to swap
    if (this->tail == this->head) {
        return;
    }

    NodeType<T> *ptr = this->head;
    NodeType<T> *before = NULL;
    while (ptr != NULL && ptr->next != NULL) {
        NodeType<T> *temp = ptr->next;
        ptr->next = temp->next;
        if (temp->next != NULL) {
            temp->next->back = ptr;
        }
        temp->next = ptr;
        ptr->back = temp;
        if (before == NULL) {
            this->head = temp;
            temp->back = NULL;
        } else {
            before->next = temp;
            temp->back = before;
        }
        before = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        this->tail = before;
    }
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
