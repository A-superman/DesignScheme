/*
外观模式：伪系统中的一组接口提供一个统一的高层接口，这个接口使得子系统更容易使用
*/

#include <iostream>
#include <memory>

using namespace std;

class Miner {
public:
    void mining() {
        cout << "矿工开采金刚石。" << endl;
    }
};

class Metallurgyer {
public:
    void Metallurgy() {
        cout << "冶金工人冶炼银子。" << endl;
    }
};

class Sander {
public:
    void sanding() {
        cout << "打磨机分别制造出钻石和指环。" << endl;
    }
};

class Worker {
public:
    void work() {
        cout << "组装钻石和指环，制造出钻戒。" << endl;
    }
};

class Packager {
public:
    void package() {
        cout << "包装工进行包装。" << endl;
    }
};

class Seller {
public:
    void sendout() {
        cout << "商家发货。" << endl;
    }
};

class Deliver {
public:
    void express() {
        cout << "快递运输送达。" << endl;
    }
};

class Customer {
public:
    void signfor() {
        cout << "顾客签收快递，得到钻戒。" << endl;
    }
};

class OnlineShoping {
public:
    OnlineShoping() {
        miner = make_unique<Miner>();
        meta = make_unique<Metallurgyer>();
        sander = make_unique<Sander>();
        worker = make_unique<Worker>();
        packager = make_unique<Packager>();
        seller = make_unique<Seller>();
        deliver = make_unique<Deliver>();
        customer = make_unique<Customer>();
    }
    void CustomizedDiamondRing() {
        cout << "顾客定制了一枚钻戒。" << endl;
        miner->mining();
        meta->Metallurgy();
        sander->sanding();
        worker->work();
    }
    void getDiamondRing() {
        cout << "顾客得到一枚钻戒。" << endl;
        packager->package();
        seller->sendout();
        deliver->express();
        customer->signfor();
    }
private:
    unique_ptr<Miner> miner;
    unique_ptr<Metallurgyer> meta;
    unique_ptr<Sander> sander;
    unique_ptr<Worker> worker;
    unique_ptr<Packager> packager;
    unique_ptr<Seller> seller;
    unique_ptr<Deliver> deliver;
    unique_ptr<Customer> customer;
};

int main() {
    unique_ptr<OnlineShoping> shoping = make_unique<OnlineShoping>();
    shoping->CustomizedDiamondRing();
    cout << "----------------------------------" << endl;
    shoping->getDiamondRing();
    return 0;
}