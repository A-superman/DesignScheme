#include "MyList.h"
#include "Iterator.h"

Node::Node() : data(0), pre(nullptr), next(nullptr) {}

MyList::MyList() : count(0) {}

MyList::~MyList() {
    while(head) {
        Node* now = head;
        head = head->next;
        delete now;
    }
}

Node* MyList::getHead() {
    return head;
}
Node* MyList::getTail() {
    return tail;
}
int MyList::getCount() {
    return count;
}
void MyList::insert(Node* pos, int data) {
    if(pos == head) {
        push_front(data);
    } else if(pos == tail) {
        push_tail(data);
    } else {
        Node* node = new Node;
        node->data = data;
        node->next = pos;
        node->pre = pos->pre;
        node->pre->next = node;
        pos->pre = node;
        ++count;
    }
}
void MyList::push_front(int data) {
    Node* node = new Node;
    node->data = data;
    if(count == 0) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head->pre = node;
        head = node;
    }
    ++count;
}
void MyList::push_tail(int data) {
    Node* node = new Node;
    node->data = data;
    if(count == 0) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        node->pre = tail;
        tail = node;
    }
    ++count;
}

AbstractIterator* MyList::getIterator(bool forward) {
    if(forward) {
        return new forwardIterator(this);
    } 
    return new reverseIterator(this);
}