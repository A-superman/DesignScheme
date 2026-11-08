#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class unit : public enable_shared_from_this<unit> {
public:
    unit(string name): name(name), parent(nullptr) {}
    unit(const unit* u) {
        name = u->name;
        parent = u->parent;
    }
    virtual void introduction() {}
    virtual void addChirld(weak_ptr<unit> child) {}
    virtual void deleteChirld() {}
    string getname() {
        return name;
    }
    virtual void competition() {}
    virtual void addgroup(shared_ptr<unit> g){
        g->addChirld(shared_from_this());
        this->parent = g;
    }
    virtual ~unit() {}
protected:
    string name;
    shared_ptr<unit> parent;
};

class group : public unit {
public:
    using unit::unit;
    void introduction() override {
        cout << "大家好，我们是" << name << "组，口号是“努力就会有回报”!" << endl;
    }
    void addChirld(weak_ptr<unit> child) override {
        chirldren.push_back(child);
    }
    void deleteChirld() override {
        chirldren.pop_back();
    }
    void competition() override {
        cout<< name << "组加入比赛。" << endl;
    }
    ~group() {
        cout << name <<"组结束了比赛。" << endl;
    }
private:
    vector<weak_ptr<unit>> chirldren;
};

class member: public unit {
public:
    using unit::unit;
    void introduction() override {
        cout << "大家好，我是" << name << "，来自" << parent->getname() << "组" << endl;
    }
    void competition() override {
        cout<< name << "加入比赛。" << endl;
    }
    ~member() {
        cout << name <<"完成了比赛。" << endl;
    }
};

int main() {
    shared_ptr<unit> g = make_shared<group>("安徽大学");
    g->introduction();
    g->competition();
    vector<string> groupnamelist = {"24研究生学硕组", "24研究生专硕组", "25研究生学硕组", "25研究生专硕组"};
    for(auto name : groupnamelist) {
        shared_ptr<unit> subg = make_shared<group>(name);
        subg->addgroup(g);
        subg->introduction();
        subg->competition();
        if(name == "24研究生学硕组") {
            vector<string> mems = {"小王", "小张", "小赵", "小钱", "小孙", "小李"};
            for(auto memname : mems) {
                shared_ptr<unit> mem = make_shared<member>(memname);
                mem->addgroup(subg);
                mem->introduction();
                mem->competition();
            }
        }
    }
    return 0;
}