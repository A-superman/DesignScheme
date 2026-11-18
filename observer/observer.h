#include <string>

class subject;

class observer {
public:
    observer(std::string n, subject* s);
    void unsub();
    virtual void update(std::string) = 0;
protected:
    std::string name;
    subject *s;
};

class teacher : public observer {
public: 
    using observer::observer;
    void update(std::string) override;
};

class student : public observer {
public: 
    using observer::observer;
    void update(std::string) override;
};

class worker : public observer {
public: 
    using observer::observer;
    void update(std::string) override;
};
