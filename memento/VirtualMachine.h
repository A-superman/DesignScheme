#pragma once
#include "Snapshot.h"

class VirtualMachine {
public:
    void setState(std::string snap) {
        state = snap;
    } 
    std::string getState() {
        return state;
    }
    Snapshot* saveSnapshot() {
        return new Snapshot(state);
    }
private:
    std::string state;
};