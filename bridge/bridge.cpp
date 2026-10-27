
/*
抽象部分和实现部分分离，使二者都可以独立地进行扩展与变化
*/

#include <string>
#include <vector>
#include <iostream>


class decoration {
public:
    decoration(std::string name, std::string color, std::string type) 
        : name(name), color(color), type(type) {}
    virtual ~decoration() {}

    std::string name;
    std::string color;
    std::string type;
};

class styling {
public:
    void addunit(decoration d) {
        subunits.push_back(d);
    }
    void showStyling() {
        std::cout << "我的穿搭：" << "\n";
        for(const auto &item : subunits) {
            std::cout << item.type << ":" << item.color << item.name << std::endl;
        }
    }
    virtual void description() = 0;
protected:
    std::vector<decoration> subunits;
};

class casualStyling : public styling {
public:
    void description() override {
        std::cout << "***休闲风：宽松舒适为主，不强调曲线，可塑性强。" << std::endl;
    }
};

class streetStyling : public styling {
public:
    void description() override {
        std::cout << "***街头风：偏前卫潮流，带点不羁感。" << std::endl;
    }
};

class preppyStyling : public styling {
public:
    void description() override {
        std::cout << "***学院风：像英伦校园里的穿搭，乖巧又有书卷气。" << std::endl;
    }
};

class person {
public:
    person(styling* sty): style(sty) {}
    virtual void stylingIntroduce() = 0;
    void showStyling() {
        style->showStyling();
    }
    virtual ~person() {}
private:
    styling* style;
}; // styling和person桥接，抽象层和实现层分离，两个抽象都可增长

class streetPerson : public person {
public:
    using person::person;
    void stylingIntroduce() override {
        std::cout << "我是一个街舞人" << std::endl; 
    }
};

class studentPerson : public person {
public:
    using person::person;
    void stylingIntroduce() override {
        std::cout << "我是一个学生" << std::endl; 
    }
};

class workerPerson : public person {
public:
    using person::person;
    void stylingIntroduce() override {
        std::cout << "我是一个上班族" << std::endl; 
    }
};

int main() {
    styling* street = new streetStyling();
    decoration cap("棒球帽", "红色", "头饰");
    decoration lap("大T", "蓝色", "上衣");
    decoration garment("工装裤", "牛仔蓝", "裤子");
    decoration shoe("板鞋", "白色", "鞋子");
    street->addunit(cap);
    street->addunit(lap);
    street->addunit(garment);
    street->addunit(shoe);
    person* hiphoper = new streetPerson(street);
    hiphoper->stylingIntroduce();
    hiphoper->showStyling();

    delete street;
    delete hiphoper;

    return 0;
}

