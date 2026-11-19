#include "element.h"
#include "visitor.h"

void elementA::excute(visitor* v) {
    v->visit(this);
}

void elementB::excute(visitor* v) {
    v->visit(this);
}