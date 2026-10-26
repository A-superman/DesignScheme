/*
将一个类的接口转换成用户希望的另一个接口，使不兼容的对象能够相互配合并一起工作，这种模式就叫适配器模式。

*/
#include <iostream>
#include <vector>
#include <string>

class parent { // 已存在旧接口
public:
    void getFeedback(std::string says) {
        std::cout << "son : " << says << std::endl;
    }
    virtual std::string estimate() = 0;
    virtual ~parent() {}
};

class father : public parent {
public:
    std::string estimate() override {
        return std::string("考的太少了，还需继续努力！");
    }
};

class mother : public parent {
public:
    std::string estimate() override {
        return std::string("考的太棒了，今晚吃大餐！");
    }    
};

class son {
public:
    void recvEstimate(std::string estmt) {
        std::cout << estmt << std::endl;
    }
    std::string sendScore() {
        return "我考了90分。";
    }
};

class transfer { // 用户期望的接口
public:
    transfer(parent* pt) : p(pt) {}
    virtual void transferToSon() = 0;
    virtual void transferToParent() = 0;
    virtual ~transfer() {}
protected:
    son s;
    parent* p;
};

class motherTransfer : public transfer { // 适配器
public:
    motherTransfer(parent* p) : transfer(p) {}
    void transferToSon() override { // 新接口
        std::string msg = p->estimate(); // 旧接口
        s.recvEstimate("mother says : " + msg);
    }
    void transferToParent() override {
        std::string msg = s.sendScore();
        p->getFeedback("mother, " + msg);
    }
};

class fatherTransfer : public transfer { // 适配器
public:
    fatherTransfer(parent* p) : transfer(p) {}
    void transferToSon() override {
        std::string msg = p->estimate();
        s.recvEstimate("father says : " + msg);
    }
    void transferToParent() override {
        std::string msg = s.sendScore();
        p->getFeedback("father, " + msg);
    }
};

int main() {
    parent* p = new mother();
    transfer* t = new motherTransfer(p);
    t->transferToParent();
    t->transferToSon();
    delete p;
    delete t;

    p = new father;
    t = new fatherTransfer(p);
    t->transferToParent();
    t->transferToSon();    
    delete p;
    delete t;

    return 0;
}
