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