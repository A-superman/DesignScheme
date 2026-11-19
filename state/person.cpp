/*
状态模式：
对象的行为取决于他当前的状态；状态切换时，行为自动跟着变，把每个状态封装成独立类。
区别于策略模式。
*/

#include "person.h"
#include "state.h"

person::person() : ml(new breakfast) {}

void person::setState(meal* s) {
    if(ml != nullptr) {
        delete ml;
    }
    ml = s;
}

meal* person::getState() {
    return ml;
}

void person::doSomthing() {
    if(ml != nullptr) {
        ml->eat(this);
    }
}

int person::getClock() {
    return clockNow;
}
void person::setClock(int c) {
    clockNow = c;
}

person::~person() {
    delete ml;
}
