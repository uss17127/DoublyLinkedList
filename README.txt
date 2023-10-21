Program: main.cpp DoublyLinkedList.cpp
------------------------------------------------------------------------
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
------------------------------------------------------------------------
CODER: Urja Shah
Credit/Contribution:
    - Assignment 3 pdf  - also used for comments

How to Compile:
g++ main.cpp DoublyLinkedList.cpp -o main
