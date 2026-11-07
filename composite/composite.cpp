#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class unit {
public:
    unit(string name): name(name) {}
    virtual void introduction();
    virtual void addChirld();
    virtual void deleteChirld();
    virtual void competition();
protected:
    string name;
};

class group : public unit {
public:
    using unit::unit;
    virtual void introduction();
    virtual void addChirld();
    virtual void deleteChirld();
    virtual void competition();
private:
    vector<unique_ptr<unit>> chirldren;
};

class member: public unit {
public:
    using unit::unit;

};