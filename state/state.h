#include <iostream>


class person;
class meal {
public:
    virtual void eat(person* clock) = 0;
    virtual ~meal() = default;
};

class breakfast : public meal{
public:
    void eat(person* p) override;

};

class lunch : public meal {
public:
    void eat(person* p) override;
};

class dinner : public meal {
public:
    void eat(person* p) override;
};

class sleep : public meal {
public:
    void eat(person* p) override;
};