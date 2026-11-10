/*
享元模式：摒弃在每个对象中都保存所有的数据，通过数据共享让有限的内存可以加载更多的对象。
        （复用对象，减少相似对象的内存开销。）
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <random>

using namespace std;

class flyweight {
public:
    flyweight(string name) : name(name) {}
    virtual void KeepWatch(string site) = 0;
protected:
    string name; 
    string department = "研发";
};

class worker : public flyweight {
public:
    using flyweight::flyweight;
    void KeepWatch(string site) override{
        cout << department << " 部门的 " << name << " 今天在 " << site << " 值班。" <<endl;
    }
};

class leader : public flyweight {
public:
    using flyweight::flyweight;
    void KeepWatch(string site) override {
        cout << department << "部门的领导 " << name << " 今天在 " << site << " 值班。" <<endl;
    }
};

class workerFactory {
public:
    shared_ptr<flyweight> turnWorker(string name) {
        auto it = staff.find(name);
        if(it != staff.end()) {
            cout << "老员工轮岗。" ;
            return it->second;
        } else {
            shared_ptr<flyweight> newWorker = make_shared<worker>(name);
            staff.insert({name, newWorker});
            cout << "新员工第一天轮岗。";
            return newWorker;
        }
    }
private:
    unordered_map<string, shared_ptr<flyweight>> staff;
};

int main() {
    vector<string> staffname = {"小赵", "小钱", "小孙", "小李", "小周", "小赵", "小钱", "小孙", "小李", "小周"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);
    workerFactory factory;
    for(const string &name : staffname) {
        shared_ptr<flyweight> worker = factory.turnWorker(name);
        for(int i = 0; i < 3; ++i) {
            int r = dist(gen);
            worker->KeepWatch(to_string(r) + "号楼");
        }
    }
    unique_ptr<flyweight> ld = make_unique<leader>("吴总");
    for(int i = 0; i < 3; ++i) {
        int r = dist(gen);
        ld->KeepWatch(to_string(r) + "号楼");
    }
    return 0;
}