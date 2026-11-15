

struct Node
{
    Node();
    int data;
    Node* pre;
    Node* next;
};

class AbstractIterator;

class MyList {
public:
    MyList();
    ~MyList();
    Node* getHead();
    Node* getTail();
    int getCount();
    void insert(Node* pos, int data);
    void push_front(int data);
    void push_tail(int data);
    AbstractIterator* getIterator(bool forward = false);
private:
    Node* head;
    Node* tail;
    int count;
};
