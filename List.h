#ifndef LIST_H
#define LIST_H

class List {
private:
    struct node {
        int key;
        char data;
        node* next;
    };
    
    node* head;
    node* prev;
    node* cursor;

public:
    List();                          // Constructor
    ~List();                         // Destructor

    bool listIsEmpty();
    bool curIsEmpty();
    void toFirst();
    bool atFirst();
    void advance();
    void toEnd();
    bool atEnd();
    int listSize();
    void updateData(char d);
    void updateKey(int k);
    char retrieveData();
    void insertFirst(int k, char d);
    void insertAfter(int k, char d);
    void insertBefore(int k, char d);
    void insertEnd(int k, char d);
    void deleteNode();
    void deleteFirst();
    void deleteEnd();
    void makeListEmpty();
    bool search(const int& k);
    void traverse();
    void orderinsert(int k, char d);
};
