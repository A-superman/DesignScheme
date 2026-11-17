/*
备忘录模式：
在不破坏对象封装的前提下，捕获对象内部状态并保存，后续客回复到之前的状态（撤销/回滚）。
*/

#include <iostream>
#include <string>
#include <vector>
#include "Snapshot.h"
#include "Memento.h"
#include "VirtualMachine.h"

int main() {
    std::vector<std::string> versionlist = {"完成方案部分。", "完成调研工作。", "代码框架搭建完成。", "补充功能填充。", "初步跑通实验。"};
    VirtualMachine* machine = new VirtualMachine();
    Momento* momento = new Momento();
    for(int i = 0; i < versionlist.size(); i++) {
        machine->setState(versionlist[i]);
        momento->push(i, machine->saveSnapshot());
    }
    for(int i = 0; i < versionlist.size(); i++) {
        machine->setState(momento->get(i)->getState());
        std::cout << "虚拟机状态：" << machine->getState() << std::endl;
    }
    return 0;
}