#include <unordered_map>
#include <string>

class Colleague;

class Mediator {
public:
    virtual void sayTo(std::string msg, Colleague* from, std::string toname = std::string()) = 0;
    void addColleague(Colleague* c);
    virtual ~Mediator() = default;
protected:
    std::unordered_map<std::string, Colleague*> Clist;
};

class companyAMediator : public Mediator {
public:
    void sayTo(std::string msg, Colleague* from, std::string toname = std::string()) override;
};

class companyBMediator : public Mediator {
public:
    void sayTo(std::string msg, Colleague* from, std::string toname = std::string()) override;
};