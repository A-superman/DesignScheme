#include "Mediator.h"
#include "Colleague.h"

#include <iostream>

void Mediator::addColleague(Colleague* c) {
    auto it = Clist.find(c->getname());
    if(it == Clist.end()) {
        Clist.insert(make_pair(c->getname(), c));
    } 
}

void companyAMediator::sayTo(std::string msg, Colleague* from, std::string toname) {
    auto it = Clist.find(toname);
    if(it != Clist.end()) {
        std::cout << from->getname() << " 对 " << toname << " 说 " << msg << std::endl;
    }
}

void companyBMediator::sayTo(std::string msg, Colleague* from, std::string toname) {
    for(const auto &it: Clist) {
        if(it.first != from->getname()) {
            std::cout << from->getname() << " 说 " << msg << std::endl;
        }
    }
}