#include <list>
#include <string>

class observer;
class subject {
public:
    virtual void subscribe(observer* ob);
    virtual void unsubscribe(observer* ob);
    virtual void publish(std::string) = 0;
    virtual ~subject() = default;
protected:
    std::list<observer*> ob_list;
};

class reader : public subject {
public:
    void publish(std::string)  override;
};

class qingting : public subject {
public:
    void publish(std::string)  override;
};