

#include "person.h"
#include "state.h"

#include <vector>

int main() {
    std::vector<int> times{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    person* p = new person();
    for(int i = 0 ; i < times.size(); ++i) {
        p->setClock(times[i]);
        p->doSomthing();
    }
    delete p;

    return 0;
}