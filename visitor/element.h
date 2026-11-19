
class visitor;
class element {
public:
     virtual void excute(visitor* v) = 0;
};

class elementA : public element {
public:
    void excute(visitor* v) override;
};

class elementB : public element {
public:
    void excute(visitor* v) override;
};