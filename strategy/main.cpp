/*
策略模式：
定义一组算法，把每个算法封装成独立类，让他们可以相互替换；算法独立于使用他们的客户端。
*/
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