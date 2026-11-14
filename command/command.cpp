/*
命令模式：把请求封装成一个对象，可以使用不同的请求、排队请求、记录请求、撤销请求。
核心：解耦调用者和执行者，调用者不需要知道谁执行、怎么执行。
*/
#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <string>

using namespace std;

class kitchener {
public:
    void makeZJF() {
        cout << "制作猪脚饭。" << endl;
    }

    void makeKRF() {
        cout << "制作烤肉饭。" << endl;
    }

    void makeJGB() {
        cout << "制作鸡公煲。" << endl; 
    }

    void makeGQMX() {
        cout << "制作过桥米线。" << endl;
    }
};

class dishes {
public:
    dishes(shared_ptr<kitchener> kc) : kc(kc) {}
    virtual void make() = 0;
    virtual string dishName() = 0;
    virtual ~dishes() = default;
protected:
    shared_ptr<kitchener> kc;
};

class ZJF : public dishes {
public:
    using dishes::dishes;
    void make() override {
        kc->makeZJF();
    }
    string dishName() override {
        return "猪脚饭";
    }
};

class KRF : public dishes {
public:
    using dishes::dishes;
    void make() override {
        kc->makeKRF();
    }
    string dishName() override {
        return "烤肉饭";
    }
};

class JGB : public dishes {
public:
    using dishes::dishes;
    void make() override {
        kc->makeJGB();
    }
    string dishName() override {
        return "鸡公煲";
    }
};

class GQMX : public dishes {
public:
    using dishes::dishes;
    void make() override {
        kc->makeGQMX();
    }
    string dishName() override {
        return "过桥米线";
    }
};

class waiter {
public:
    void order(int idx, shared_ptr<dishes> cuisine) {
        auto it = menu.find(idx);
        if(cuisine->dishName() == "JGB") {
            cout << "没有鸡了，请选择其他菜品。。。" << endl;
            return;
        }
        if(it != menu.end()) {
            it->second.push_back(cuisine);
        } else {
            list<shared_ptr<dishes>> ls{cuisine};
            menu.insert({idx, ls});
        }
        cout << idx << "号桌点了份" << cuisine->dishName() << endl;
    }

    void unOrder(int idx, shared_ptr<dishes> cuisine) {
        auto it = menu.find(idx);
        if(it != menu.end()) {
            it->second.remove(cuisine);
            cout << idx << "取消了" << cuisine->dishName() << endl;
        }
    }

    void cook(int idx) {
        auto it = menu.find(idx);
        for(const auto& item : it->second) {
            item->make();
        }
    }

    void account(int idx) {
        auto it = menu.find(idx);
        cout << idx << "号桌，点餐账单【";
        for(const auto& item : it->second) {
            if(item != *it->second.begin()) {
                cout << "，";
            }
            cout << item->dishName();
        }
        cout << "】" << endl;
    }
private:    
    map<int, list<shared_ptr<dishes>>> menu;
};

int main() {
    shared_ptr<kitchener> kc = make_shared<kitchener>();
    shared_ptr<waiter> wt = make_shared<waiter>();
    shared_ptr<dishes> z = make_shared<ZJF>(kc);
    shared_ptr<dishes> k = make_shared<KRF>(kc);
    shared_ptr<dishes> j = make_shared<JGB>(kc);
    shared_ptr<dishes> g = make_shared<GQMX>(kc);
    wt->order(1, z);
    wt->order(1, k);
    wt->order(1, j);
    wt->order(1, g);
    wt->unOrder(1, z);
    wt->order(2, z);
    wt->order(2, k);
    wt->order(2, j);
    wt->order(2, g);
    wt->cook(1);
    wt->account(1);
    wt->cook(2);
    wt->account(2);
    return 0;
}