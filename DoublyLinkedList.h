#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


template<class T>
struct NodeType {
// NodeType members
    T data;
    NodeType<T> *next;
    NodeType<T> *back;
};

template<class T>
class DoublyLinkedList {
// DoublyLinkedList members
private:
    NodeType<T> *head;
    NodeType<T> *tail;
    int length;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertItem(T &item);
    void deleteItem(T &item);
    int lengthIs() const;
    void print();
    void printReverse();
    void deleteSubsection(T &item1, T &item2);
    T mode();
    void swapAlternate();
};

#endif
