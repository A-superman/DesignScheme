#include <iostream>

class money {
public:
    virtual money* clone (money* m) = 0;
    virtual ~money() {}
};

class parValue100 : public money {
public:
    money* clone(money* m) override {
        parValue100* pv = new parValue100(*this);
    }
}