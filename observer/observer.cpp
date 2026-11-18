#include "observer.h"
#include "subject.h"

#include <iostream>

observer::observer(std::string n, subject* s) : name(n), s(s) {
    s->subscribe(this);
}
void observer::unsub() {
    s->unsubscribe(this);
}

void teacher::update(std::string s) {
    std::cout << "一位老师" << name << "收到了" << s << std::endl;
}
void student::update(std::string s) {
    std::cout << "一位学生" << name << "收到了" << s << std::endl;
}
void worker::update(std::string s) {
    std::cout << "一位工人" << name << "收到了" << s << std::endl;
}