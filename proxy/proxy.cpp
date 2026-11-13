/*
代理模式，结构型设计模式
为一个对象提供一个代理对象，由代理对象控制原对象（真实主体）的访问，
可以在不修改对象代码的前提下，在访问前后增加额外逻辑。
*/

#include <iostream>
#include <memory>

using namespace std;

class pay {
public:
    virtual void payMoney() = 0;
    virtual ~pay() = default;
};

class handwork : public pay {
public:
    void payMoney() override {
        cout << "支付10块钱。" << endl;
    }
};

class electronic : public pay {
public:
    electronic() : count(make_shared<handwork>()){}
    void payMoney() override {
        cout << "使用电子支付。";
        count->payMoney();
    }
private:
    shared_ptr<pay> count;
};

int main() {
    shared_ptr<pay> trade = make_shared<handwork>();
    trade->payMoney();
    trade.reset();
    trade = make_shared<electronic>();
    trade->payMoney();
    return 0;
}