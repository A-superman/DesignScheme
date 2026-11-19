#include <string>

class meal;

class person {
public:
    person();
    void setState(meal* m);
    meal* getState();
    void doSomthing();
    int getClock();
    void setClock(int c);
    ~person();

private:
    int clockNow;
    meal* ml;
};