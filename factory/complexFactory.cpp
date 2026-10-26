// 生产的对象复杂的情况下用到
#include <iostream>

class shirt {
public:
    virtual void shirtlen() = 0;
    virtual ~shirt() {}
};
class shortShirt : public shirt {
public:
    void shirtlen() override {
        std::cout << "上衣长度55" << std::endl;
    }
};
class mediumShirt : public shirt {
public:
    void shirtlen() override {
        std::cout << "上衣长度61" << std::endl;
    }
};
class oversizeShirt : public shirt {
public:
    void shirtlen() override {
        std::cout << "上衣长度68" << std::endl;
    }
};

class trouser {
public:
    virtual void trouserlen() = 0;
    virtual ~trouser() {}
};
class shortSrouser : public trouser {
public:
    void trouserlen() override {
        std::cout << "裤子长度50" << std::endl;
    }
};
class mediumSrouser : public trouser {
public:
    void trouserlen() override {
        std::cout << "裤子长度89" << std::endl;
    }
};
class oversizeSrouser : public trouser {
public:
    void trouserlen() override {
        std::cout << "裤子长度104" << std::endl;
    }
};

class cap {
public:
    virtual void capcolor() = 0;
    virtual ~cap() {}
};
class blackCap : public cap {
public:
    void capcolor() override {
        std::cout << "帽子颜色黑色" << std::endl;
    }
};
class whiteCap : public cap {
public:
    void capcolor() override {
        std::cout << "帽子颜色白色" << std::endl;
    }
};
class blueCap : public cap {
public:
    void capcolor() override {
        std::cout << "帽子颜色蓝色" << std::endl;
    }
};

class outfit {
public:
    virtual void makeTody() = 0;
    virtual ~outfit() {} 
};

class smallOutfit : public outfit {
public:
    smallOutfit(cap* c, shirt* s, trouser* t) : c(c), s(s), t(t) {}
     void makeTody() override {
        std::cout  << "smallOutfit" << std::endl;
        c->capcolor();
        s->shirtlen();
        t->trouserlen();
    }
    ~smallOutfit() {
        delete c;
        delete s;
        delete t;
     }
private:
     cap* c;
     shirt* s;
     trouser* t;
};
class mediumOutfit : public outfit {
public:
    mediumOutfit(cap* c, shirt* s, trouser* t) : c(c), s(s), t(t) {}
     void makeTody() override {
        std::cout  << "mediumOutfit" << std::endl;
        c->capcolor();
        s->shirtlen();
        t->trouserlen();
     }
    ~mediumOutfit() {
        delete c;
        delete s;
        delete t;
     }
private:
     cap* c;
     shirt* s;
     trouser* t;
};
class oversizeOutfit : public outfit {
public:
    oversizeOutfit(cap* c, shirt* s, trouser* t) : c(c), s(s), t(t) {}
     void makeTody() override {
        std::cout  << "oversizeOutfit" << std::endl;
        c->capcolor();
        s->shirtlen();
        t->trouserlen();
     }
     ~oversizeOutfit() {
        delete c;
        delete s;
        delete t;
     }
private:
     cap* c;
     shirt* s;
     trouser* t;
};

int main() {
    outfit* ooutfit = new oversizeOutfit(new blackCap(), new oversizeShirt(), new oversizeSrouser());
    ooutfit->makeTody();
    outfit* soutfit = new smallOutfit(new blueCap(), new shortShirt(), new oversizeSrouser());
    soutfit->makeTody();
    delete ooutfit;
    delete soutfit;
    return 0;
}