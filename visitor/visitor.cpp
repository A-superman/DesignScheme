#include "visitor.h"
#include <iostream>

void visitor1::visit(elementA* A) {
    std::cout << "visitor1 访问了 elementA" << std::endl;
}
void visitor1::visit(elementB* B) {
    std::cout << "visitor1 访问了 elementB" << std::endl;
}

void visitor2::visit(elementA* A) {
    std::cout << "visitor2 访问了 elementA" << std::endl;
}
void visitor2::visit(elementB* B) {
    std::cout << "visitor2 访问了 elementB" << std::endl;
}
