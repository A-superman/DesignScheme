// 解决简单工厂模式开闭原则问题
#include <iostream>
#include <memory>

class animal {
public:
    virtual void call() = 0;
    virtual void name() = 0;
    virtual ~animal(){}
};

class cat : public animal {
public:
    void call() override {
        std::cout << "喵喵" << std::endl;
    }
    void name () override {
        std::cout << "178" << std::endl;
    }
};

class dog : public animal {
public:    
    void call() override {
        std::cout << "汪汪" << std::endl;
    }
    void name() override {
        std::cout << "豆豆" << std::endl;
    }
};

class cow : public animal {
public:    
    void call() override {
        std::cout << "哞哞" << std::endl;
    }
    void name() override {
        std::cout << "花花" << std::endl;
    }
};

class factory {
public:
    virtual animal* createAnimal() = 0;
    virtual ~factory() {}
};

class catFactory : public factory {
public:
    animal* createAnimal() override {
        return new cat;
    }
    ~catFactory() {
        std::cout << "小猫工厂倒闭了。。。" << std::endl;
    }
};

class dogFactory : public factory {
public:
    animal* createAnimal() override {
        return new dog;
    }
    ~dogFactory() {
        std::cout << "小狗工厂倒闭了。。。" << std::endl;
    }
};

class cowFactory : public factory {
public:
    animal* createAnimal() override {
        return new cow;
    }
    ~cowFactory() {
        std::cout << "小牛工厂倒闭了。。。" << std::endl;
    }
};

int main() {
    std::unique_ptr<factory> catfac = std::make_unique<catFactory>();
    std::unique_ptr<animal> acat(catfac->createAnimal());
    std::unique_ptr<factory> dogfac = std::make_unique<dogFactory>();
    std::unique_ptr<animal> adog(dogfac->createAnimal());
    std::unique_ptr<factory> cowfac = std::make_unique<cowFactory>();
    std::unique_ptr<animal> acow(cowfac->createAnimal());
    acat->name();
    acat->call();
    adog->name();
    adog->call();
    acow->name();
    acow->call();
    return 0;
}