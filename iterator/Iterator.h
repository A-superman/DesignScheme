
class Node;
class MyList;

class AbstractIterator {
public:
    AbstractIterator(MyList *list) : list(list) {}
    virtual void next() = 0;
    Node* getNow();
    virtual ~AbstractIterator();
protected:
    MyList* list;
    Node* current;
};

class forwardIterator : public AbstractIterator {
public:
    forwardIterator(MyList *list);
    void next() override;
};

class reverseIterator: public AbstractIterator {
public:
    reverseIterator(MyList *list);
    void next() override;
};