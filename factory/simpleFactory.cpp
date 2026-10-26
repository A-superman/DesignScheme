// 简单工厂模式违反开闭原则（对扩展开放，对修改封闭）
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

enum class type : char {
    cat,
    dog,
    cow
};

class factory {
public:
    animal* createAnimal(type t) {
        switch (t)
        {
            case type::cat :
                return new cat();
                break;
            case type::dog :
                return new dog();
                break;
            case type::cow :
                return new cow();
                break;
            default:break;
        }
        return nullptr;
    }
};

int main() {
    std::unique_ptr<factory> fac = std::make_unique<factory>();
    std::unique_ptr<animal> acat(fac->createAnimal(type::cat));
    std::unique_ptr<animal> adog(fac->createAnimal(type::dog));
    std::unique_ptr<animal> acow(fac->createAnimal(type::cow));
    acat->name();
    acat->call();
    adog->name();
    adog->call();
    acow->name();
    acow->call();
    return 0;
}