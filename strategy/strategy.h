#include <iostream>

class strategy {
public:
    virtual void execute() = 0;
    virtual ~strategy() = default;
};

class FIFOstrategy : public strategy {
public:
    void execute() override {
        std::cout << "先进先出策略" << std::endl;
    }
};

class LIFOstrategy : public strategy {
public:
    void execute() override {
        std::cout << "后进先出策略" << std::endl;
    }
};