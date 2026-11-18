
#include "context.h"

int main() {
    strategy* s = new FIFOstrategy();
    strategy* s1 = new LIFOstrategy();
    context* c = new context();
    c->exchangeStrategy(s);
    c->excuteStrategy();
    c->exchangeStrategy(s1);
    c->excuteStrategy();
    delete s;
    delete s1;
    delete c;
    return 0;
}