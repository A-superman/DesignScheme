/*
责任链模式，行为型设计模式
把请求的发送者和接收者解耦；
多个处理者连成一条链，请求沿着链依次传递，直到有对象处理它，或者整条链走完。
*/

#include <iostream>
#include <memory>

using namespace std;

class person {
public:
    virtual void scienceAsk() = 0;
    virtual void leave() = 0;
    virtual void funding() = 0;
    virtual ~person() = default;
};

class seniorSister : public person {
public:
    seniorSister(shared_ptr<person> p) : higher(p) {}

    void scienceAsk() override {
        cout << "师姐可以指导你学术上的问题。" << endl; 
    }

    void leave() override {
        cout << "组长收到了你的请假，批准。" << endl;
    }

    void funding() override {
        cout << "组长知道你要申请经费，这个不是组长管的，帮你请示导师。" << endl;
        higher->funding();
    }
private:
    shared_ptr<person> higher;
};

class headman : public person {
public:
    headman(shared_ptr<person> p) : higher(p) {}

    void scienceAsk() override {
        cout << "组长可以知道你学术上的问题。" << endl; 
    }

    void leave() override {
        cout << "师姐收到了你的请假，但还是要请示组长。" << endl;
        higher->leave();
    }

    void funding() override {
        cout << "师姐知道你要申请经费，这个不是师姐管的，帮你请示组长" << endl;
        higher->funding();
    }
private:
    shared_ptr<person> higher;
};

class mentor : public person {
public:
    void scienceAsk() override {
        cout << "导师可以指导你学术上的问题。" << endl; 
    }

    void leave() override {
        cout << "导师收到了你的请假，批准。" << endl;
    }

    void funding() override {
        cout << "导师知道你要申请经费，进行批准。" << endl;
    }
};

enum class requests : char {
    askScience,
    askLeave,
    askFunding
};

class student {
public:
    void request(shared_ptr<person> highl, requests opt) {
        switch(opt) {
            case requests::askScience: highl->scienceAsk(); break;
            case requests::askLeave: highl->leave(); break;
            case requests::askFunding: highl->funding(); break;
            default: cout << "查无此操作！" << endl; break;
        }
    }
};

int main() {
    student ming;
    shared_ptr<person> m = make_shared<mentor>();
    shared_ptr<person> h = make_shared<headman>(m);
    shared_ptr<person> s = make_shared<seniorSister>(h);
    cout << "向师姐请求-------------------" << endl;
    ming.request(s, requests::askScience);
    ming.request(s, requests::askLeave);
    ming.request(s, requests::askFunding);
    cout << "向组长请求-------------------" << endl;
    ming.request(h, requests::askScience);
    ming.request(h, requests::askLeave);
    ming.request(h, requests::askFunding);
    cout << "向导师请求-------------------" << endl;
    ming.request(m, requests::askScience);
    ming.request(m, requests::askLeave);
    ming.request(m, requests::askFunding);

    return 0;
}