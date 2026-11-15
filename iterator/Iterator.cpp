#include "Iterator.h"
#include "MyList.h"

Node* AbstractIterator::getNow() {
    return current;
}

AbstractIterator::~AbstractIterator() {
    delete current;
}

forwardIterator::forwardIterator(MyList *list) : AbstractIterator(list) {
    current = list->getHead();
}
void forwardIterator::next() {
    if(current != nullptr) {
        current = current->next;
    }
}

reverseIterator::reverseIterator(MyList *list) : AbstractIterator(list) {
    current = list->getTail();
}
void reverseIterator::next() {
    if(current != nullptr) {
        current = current->pre;
    }
}

