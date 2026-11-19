#include "state.h"
#include "person.h"

void breakfast::eat(person* p) {
    if(p->getClock() >= 7 && p->getClock() <11) {
        std::cout << "吃早饭" << std::endl;
    } else {
        p->setState(new lunch);
        p->doSomthing();
    }
}

void lunch::eat(person* p) {
    if(p->getClock() >= 11 && p->getClock() < 15) {
        std::cout << "吃午饭" << std::endl;
    } else {
        p->setState(new dinner);
        p->doSomthing();
    }
}

void dinner::eat(person* p) {
    if(p->getClock() >= 15 && p->getClock() <= 24) {
        std::cout << "吃晚饭" << std::endl;
    } else {
        p->setState(new sleep);
        p->doSomthing();
    }
}

void sleep::eat(person* p) {
    if(0 <= p->getClock() && p->getClock() < 7 ) { 
        std::cout << "睡觉吧！别吃了！" << std::endl;
    } else {
        p->setState(new breakfast);
        p->doSomthing();
    }
}