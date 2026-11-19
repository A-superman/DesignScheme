
class elementA;
class elementB;
class visitor {
public:
    virtual void visit(elementA* A) = 0;
    virtual void visit(elementB* B) = 0;
};

class visitor1 : public visitor {
public:
    void visit(elementA* A) override;
    void visit(elementB* B) override;
};

class visitor2 : public visitor {
public:
    void visit(elementA* A) override;
    void visit(elementB* B) override;
};