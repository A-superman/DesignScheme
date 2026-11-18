
#include "strategy.h"

class context {
public:
    context() : st(nullptr) {}
    void exchangeStrategy(strategy* s) {
        st = s;
    }
    void excuteStrategy() {
        if(st != nullptr) {
            st->execute();
        }
    }
private:
    strategy* st;
};