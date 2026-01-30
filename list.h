#include <iostream>
#ifndef LIST_H
#define LIST_H
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;

    void clear();
    void copyFrom(const List& other);

public:
    List();
    ~List();
    List(const List& other);
    List& operator=(const List& other);

    void append(int value);
    void prepend(int value);
    List removeConsecutiveDuplicates() const;
    void print() const;

    // Helper methods for testing
    Node* getHead() const;
    bool isEmpty() const;
    int size() const;
    bool equals(const List& other) const;
    int at(int index) const;
};

#endif