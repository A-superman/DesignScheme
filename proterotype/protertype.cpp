/*
原型模式：基类指针指向派生类对象，能够通过基类指针对派生类进行复制。

实例：不同面值人民币的复制。
*/

#include <iostream>
#include <vector>

class money {
public:
    virtual money* clone () = 0;
    virtual void printValue() = 0;
    virtual ~money() {}
};

class parValue100 : public money {
public:
    money* clone() override {
        parValue100* pv = new parValue100(*this);
        return pv;
    }
    void printValue() {
        std::cout << "面值100元。" << std::endl;
    }
};

class parValue50 : public money {
public:
    money* clone() override {
        parValue50* pv = new parValue50(*this);
        return pv;
    }
    void printValue() {
        std::cout << "面值50元。" << std::endl;
    }
};

void printWallet(const std::vector<money*>& wallet) {
    for(const auto &bill : wallet) {
        bill->printValue();
    }
}

void deleteWallet(const std::vector<money*>& wallet) {
    for(auto &bill : wallet) {
        delete bill;
    }
}

int main() {
    std::vector<money*> wallet;
    money* mn100 = new parValue100;
    money* mn50 = new parValue50;
    wallet.emplace_back(mn100);
    wallet.emplace_back(mn50);
    std::vector<money*> newWallet;
    for(const auto &bill : wallet) {
        money* newbill = bill->clone();
        newWallet.emplace_back(newbill);
    }
    std::cout << "模型钱包里的钱：" << std::endl;
    printWallet(wallet);
    
    std::cout << "新钱包里的钱：" << std::endl;
    printWallet(newWallet);

    deleteWallet(wallet);
    deleteWallet(newWallet);
    
    return 0;
}