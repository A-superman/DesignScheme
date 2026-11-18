/*
观察者模式：
核心：定义一对多依赖，当目标（被观察者）状态变化时，
自动通知所有注册的观察者，观察者自行响应更新，双方解耦。
*/

#include <iostream>
#include "subject.h"
#include "observer.h"

int main() {
    subject* r = new reader;
    subject* q = new qingting;
    observer* s1 = new student("学生A", r);
    observer* s2 = new student("学生b", q);
    observer* t1 = new teacher("教师A", r);
    observer* w1 = new worker("工人b", q);

    r->publish("刊物1");
    q->publish("漫画1");

    delete r;
    delete q;
    delete s1;
    delete s2;
    delete t1;
    delete w1;

    return 0;
}