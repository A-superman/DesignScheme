/*
模板方法：
核心：父类定义完整算法骨架，固定执行步骤；子类重写其中的可变步骤，不能改变整体流程。
*/

#include <iostream>

class model {
public:
    virtual void process() final {
        step1();
        step2();
        step3();
    }
private:
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() {
        std::cout << "所有流程结束" << std::endl;
    }
};

class stream1 : public model {
private:
    void step1() override {
        std::cout << "stream1的步骤1" << std::endl;
    }
    void step2() override {
        std::cout << "stream1的步骤2" << std::endl;
    }
};

class stream2 : public model {
public:
    void step1() override {
        std::cout << "stream2的步骤1" << std::endl;
    }
    void step2() override {
        std::cout << "stream2的步骤2" << std::endl;
    }
    void step3() override {
        std::cout << "stream2的步骤3" << std::endl;
    }
};

int main() {
    model* m = new stream1;
    m->process();
    delete m;
    m = new stream2;
    m->process();
    delete m;
    return 0;
}