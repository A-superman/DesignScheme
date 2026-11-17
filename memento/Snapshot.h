#pragma once
#include <string>

class Snapshot {
public:
    Snapshot(std::string s) : state(s) {}
    std::string getState() {
        return state;
    }
private:
    std::string state;
};