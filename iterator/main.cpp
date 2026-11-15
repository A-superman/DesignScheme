/*
迭代器模式：行为型模式
提供一种顺序访问集合对象元素的方式，而不暴露集合内部结构。
核心：把遍历逻辑和容器存储逻辑分开。
*/

#include <iostream>
#include "MyList.h"
#include "Iterator.h"
using namespace std;

int main() {
    MyList* list = new MyList();
    list->push_tail(1);
    list->push_tail(2);
    list->push_tail(3);
    list->push_tail(4);
    list->push_tail(5);
    list->push_tail(6);
    list->push_tail(7);
    list->push_tail(8);

    AbstractIterator *iterater = list->getIterator();

    while(iterater->getNow() != nullptr) {
        cout << iterater->getNow()->data << endl;
        iterater->next();
    }

    delete list;
    delete iterater;
    return 0;
}