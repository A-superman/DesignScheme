/*
真取经队伍：唐僧、孙悟空、白龙马、猪八戒、沙僧
假取经队伍2；猴唐僧、六耳猕猴、白马、猴悟净、猴悟净
*/
#include <iostream>
#include <vector>
#include <string>

class trueGroup {
public:
    void addMember(std::string title, std::string name){
        members.emplace_back(std::make_pair(title, name));
    }
    void printMember() {
        for(const auto &item : members){
            std::cout << item.first << ":" << item.second << std::endl;
        }
    }
private:
    std::vector<std::pair<std::string, std::string>> members;
};

class fakeGroup {
public:
    void addMember(std::string name) {
        members.emplace_back(name);
    }
    void printMember() {
        for(const auto &item : members) {
            std::cout << item << std::endl;
        }
    }
private:
    std::vector<std::string> members;
};

class finder { // builder
public:
    virtual void findMentor() = 0;
    virtual void findFirst() = 0;
    virtual void findhorse() = 0;
    virtual void findSecond() = 0;
    virtual void findThird() = 0;
    virtual void printMember() = 0;
    virtual ~finder() {}
};

class trueFinder : public finder {
public:
    void findMentor() override {
        group.addMember("mentor", "唐僧");
    }
    void findFirst() override {
        group.addMember("first", "孙悟空");
    }
    void findhorse() override {
        group.addMember("horse", "白龙马");
    }
    void findSecond() override {
        group.addMember("second", "猪悟能");
    }
    void findThird() override {
        group.addMember("third", "沙悟净");
    }
    void printMember() override {
        group.printMember();
    }
private:
    trueGroup group;
};

class fakeFinder : public finder {
public:
    void findMentor() override {
        group.addMember("猴唐僧");
    }
    void findFirst() override {
        group.addMember("六耳猕猴");
    }
    void findhorse() override {
        group.addMember("白马");
    }
    void findSecond() override {
        group.addMember("猴悟能");
    }
    void findThird() override {
        group.addMember("猴悟净");
    }
    void printMember() override {
        group.printMember();
    }
private:
    fakeGroup group;
};

class director {
public:
    director(finder* f): fd(f) {}
    ~director() {
        delete fd;
    }
    finder* givenfind() {
        finder* f = fd;
        fd = nullptr;
        return f;
    }
    void makeSingle() {
        fd->findMentor();
    }
    void makeDouble() {
        makeSingle();
        fd->findFirst();
    }
    void makeTrible() {
        makeDouble();
        fd->findhorse();
    }
    void makeFour() {
        makeTrible();
        fd->findSecond();
    }
    void makeFive() {
        makeFour();
        fd->findThird();
    }
private:
    finder* fd;
};

void makeTrueGroup() {
    finder* fd = new trueFinder;
    director dt(fd);
    std::cout << "五人取经队伍：" << std::endl;
    dt.makeFive();
    fd = dt.givenfind();
    fd->printMember();
    delete fd;
}

void makeFakeGroup() {
    finder* fd = new fakeFinder;
    director dt(fd);
    std::cout << "三人取经队伍：" << std::endl;
    dt.makeTrible();
    fd = dt.givenfind();
    fd->printMember();
    delete fd;
}

int main() {
    makeTrueGroup();
    makeFakeGroup();
    return 0;
}