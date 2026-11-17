#pragma once
#include <map>
#include "Snapshot.h"

class Momento {
public:
    void push(int idx, Snapshot* s) {
        history.insert(std::make_pair(idx, s));
    }
    Snapshot* get(int idx) {
        return history[idx];
    }
private:
    std::map<int, Snapshot*> history;
};