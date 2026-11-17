#include <string>

class Mediator;

class Colleague {
public:
    Colleague(Mediator* m) : mediator(m) {}
    void says(std::string msg, std::string another = std::string());
    virtual std::string getname() = 0;
    virtual ~Colleague() = default;
protected:
    Mediator* mediator;
};

class boss : public Colleague {
    using Colleague::Colleague;
    std::string getname() override;
};

class IT : public Colleague {
    using Colleague::Colleague;
    std::string getname() override;
};

class HR : public Colleague {
    using Colleague::Colleague;
    std::string getname() override;
};

class Treasurer : public Colleague {
    using Colleague::Colleague;
    std::string getname() override;
};