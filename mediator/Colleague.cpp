
#include "Colleague.h"
#include "Mediator.h"

void Colleague::says(std::string msg, std::string another) {
    mediator->sayTo(msg, this, another);
}

std::string boss::getname() {
    return "boss";
}

std::string IT::getname() {
    return "IT";
}

std::string HR::getname()  {
    return "HR";
}

std::string Treasurer::getname()  {
    return "Treasurer";
}
