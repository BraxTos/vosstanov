#include "List.h"
#include <iostream>
#include <stdexcept>

List::List() : head(nullptr) {}

List::~List() {
    clear();
}

List::List(const List& other) : head(nullptr) {
    copyFrom(other);
}

List& List::operator=(const List& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

void List::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::copyFrom(const List& other) {
    if (other.head != nullptr) {
        Node* otherCurrent = other.head;
        Node* tail = nullptr;

        while (otherCurrent != nullptr) {
            Node* newNode = new Node(otherCurrent->data);

            if (head == nullptr) {
                head = newNode;
            }
            else {
                tail->next = newNode;
            }
            tail = newNode;
            otherCurrent = otherCurrent->next;
        }
    }
}

void List::append(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void List::prepend(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

List List::removeConsecutiveDuplicates() const {
    List result;

    if (head == nullptr) {
        return result;
    }

    Node* current = head;
    Node* resultTail = nullptr;

    while (current != nullptr) {
        if (resultTail == nullptr) {
            result.head = new Node(current->data);
            resultTail = result.head;
        }
        else {
            if (resultTail->data != current->data) {
                resultTail->next = new Node(current->data);
                resultTail = resultTail->next;
            }
        }

        int currentValue = current->data;
        while (current != nullptr && current->data == currentValue) {
            current = current->next;
        }
    }

    return result;
}

void List::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

Node* List::getHead() const {
    return head;
}

bool List::isEmpty() const {
    return head == nullptr;
}

int List::size() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

bool List::equals(const List& other) const {
    Node* current1 = head;
    Node* current2 = other.head;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return current1 == nullptr && current2 == nullptr;
}

int List::at(int index) const {
    if (index < 0) {
        throw std::out_of_range("Index cannot be negative");
    }

    Node* current = head;
    int currentIndex = 0;

    while (current != nullptr) {
        if (currentIndex == index) {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }

    throw std::out_of_range("Index out of range");
}