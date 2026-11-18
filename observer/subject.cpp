#include "subject.h"
#include "observer.h"

#include <iostream>

void subject::subscribe(observer* ob) {
    ob_list.emplace_back(ob);
}
void subject::unsubscribe(observer* ob) {
    ob_list.remove(ob);
}

void reader::publish(std::string s) {
    std::cout << "读者新发布了一本刊物" << s << "，请订阅者们查收！" << std::endl;
    for(const auto& sub : ob_list) {
        sub->update(s);
    }
}

void qingting::publish(std::string s) {
    std::cout << "青听新发布了一本刊物" << s << "，请订阅者们查收！" << std::endl;
    for(const auto& sub : ob_list) {
        sub->update(s);
    }
}