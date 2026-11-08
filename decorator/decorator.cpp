/*
装饰器模式，动态的给一个对象增加额外的职责    
不修改原有类代码，也不使用继承，而是包装（组合）的方式一层层包裹对象，扩展能力。
*/
#include <iostream>
#include <memory>

using namespace std;

class hero {
public:
    hero(string n) : name(n) {}
    string getname() {
        return name;
    }
    virtual void ability() = 0;
    virtual ~hero(){}
protected:
    string name;
};

class SunWukong : public hero {
public:
    using hero::hero;
    void ability() override {
        cout << name << "会七十二般变化。" << endl;
    }
};

class weapon : public hero {
public:
    weapon(shared_ptr<hero> h) : hero(h->getname()) {
        this->h = h;
    }
protected:
    shared_ptr<hero> h;
};

class Jindouyun : public weapon {
public:
    using weapon::weapon;
    void ability() {
        h->ability();
        cout << name << "得到了筋斗云，一个跟头十万八千里。" << endl; 
        limit();
    }
private:
    void limit() {
        cout << "但是不能直接载师傅飞到西天，师傅只能走路或骑马去。" << endl;
    }
};

class Jingubang : public weapon {
public:
    using weapon::weapon;
    void ability() {
        h->ability();
        cout << name << "得到了金箍棒，碰着则死，擦着就伤。可大可小。" << endl; 
        origin();
    }
private:
    void origin() {
        cout << "如意金箍棒是东海老龙王那里的定海神针。" << endl;
    }
};

class jingu : public weapon {
public:
    using weapon::weapon;
    void ability() {
        h->ability();
        cout << name << "得到了紧箍，唐僧念紧箍咒，就会头痛无比。" << endl; 
    }
};

int main() {
    shared_ptr<hero> h = make_shared<SunWukong>("齐天大圣");
    shared_ptr<weapon> w1 = make_shared<Jindouyun>(h);
    shared_ptr<weapon> w2 = make_shared<Jingubang>(w1);
    shared_ptr<weapon> w3 = make_shared<jingu>(w2);
    w3->ability();

    return 0;
}