/*
中介者模式：
用一个中介对象封装一组对象之间的交互，让个对象不再直接互相引用，全部通过中介通信，解除多对多耦合。
*/

#include <iostream>

#include "Mediator.h"
#include "Colleague.h"

int main() {
    Mediator* companyA = new companyAMediator;
    Mediator* companyB = new companyBMediator;
    Colleague* b = new boss(companyA);
    Colleague* i = new IT(companyA);
    Colleague* h = new HR(companyB);
    Colleague* t = new Treasurer(companyB);
    companyA->addColleague(b);
    companyA->addColleague(i);
    companyB->addColleague(h);
    companyB->addColleague(t);

    i->says("我身体不舒服，要请个假。", b->getname());
    b->says("好的，批准了，注意身体！", i->getname());

    t->says("明天要发工资了");

    delete companyA;
    delete companyB;
    delete b;
    delete i;
    delete h;
    delete t;

    return 0;
}