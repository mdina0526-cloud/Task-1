#include "List.h"
#include <iostream>
using namespace std;

List::List() {
    head = nullptr;
    prev = nullptr;
    cursor = nullptr;
}

bool List::listIsEmpty() {
    return (head == nullptr);
}

bool List::curIsEmpty() {
    return (cursor == nullptr);
}

void List::toFirst() {
    cursor = head;
    prev = nullptr;
}

bool List::atFirst() {
    if (listIsEmpty()) return curIsEmpty();
 return (cursor == head);
}

void List::advance() {
    if (cursor != nullptr && cursor->next != nullptr) {
        prev = cursor;
        cursor = cursor->next;
    }
}

void List::toEnd() {
    if (!listIsEmpty()) {
        toFirst();
        while (cursor->next != nullptr) {
            advance();
        }
    }
}

bool List::atEnd() {
    if (listIsEmpty()) return curIsEmpty();
    return (cursor == nullptr || cursor->next == nullptr);
}

int List::listSize() {
    int count = 0;
    node* p = head;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void List::updateData(char d) {
    if (!curIsEmpty()) cursor->data = d;
}

void List::updateKey(int k) {
    if (!curIsEmpty()) cursor->key = k;
}

char List::retrieveData() {
    return curIsEmpty() ? '\0' : cursor->data;
}

void List::insertFirst(int k, char d) {
    node* p = new node{k, d, head};
    head = p;
    cursor = head;
    prev = nullptr;
}

void List::insertAfter(int k, char d) {
    if (curIsEmpty()) return;
    node* p = new node{k, d, cursor->next};
    cursor->next = p;
    prev = cursor;
    cursor = p;
}

void List::insertBefore(int k, char d) {
    if (curIsEmpty()) return;
    if (atFirst()) {
        insertFirst(k, d);
    } else {
        node* p = new node{k, d, cursor};
        prev->next = p;
        cursor = p;
    }
}

void List::insertEnd(int k, char d) {
    if (listIsEmpty()) {
        insertFirst(k, d);
    } else {
        toEnd();
        insertAfter(k, d);
    }
}

void List::deleteNode() {
    if (curIsEmpty()) return;
    node* temp = cursor;

    if (atFirst()) {
        head = cursor = cursor->next;
        prev = nullptr;
    } else {
        prev->next = cursor->next;
        cursor = cursor->next;
    }
    delete temp;
}

void List::deleteFirst() {
    if (!listIsEmpty()) {
        toFirst();
        deleteNode();
    }
}

void List::deleteEnd() {
    if (!listIsEmpty()) {
        toEnd();
        deleteNode();
    }
}

void List::makeListEmpty() {
    while (!listIsEmpty()) deleteFirst();
}

bool List::search(const int& k) {
    toFirst();
    while (cursor != nullptr) {
        if (cursor->key == k) return true;
        advance();
    }
    return false;
}

void List::traverse() {
    node* current = head;
    while (current != nullptr) {
        cout << current->data << " - " << current->key << endl;
        current = current->next;
    }
}

void List::orderinsert(int k, char d) {
    if (listIsEmpty() || k < head->key) {
        insertFirst(k, d);
        return;
    }

    toFirst();
    while (cursor->next != nullptr && cursor->next->key < k) {
        advance();
    }
    insertAfter(k, d);
}

List::~List() {
    makeListEmpty();
}
