/*
访问者模式：
核心：在不修改元素类的前提下，给元素新增一套/多套数据操作；
把数据结结构和对数据的操作分离开。
*/

#include "visitor.h"
#include "element.h"

int main() {
    element* ea = new elementA;
    element* eb = new elementB;
    visitor* v1 = new visitor1;
    visitor* v2 = new visitor2;
    ea->excute(v1);
    ea->excute(v2);
    eb->excute(v1);
    eb->excute(v2);

    delete ea;
    delete eb;
    delete v1;
    delete v2;

    return 0;
}