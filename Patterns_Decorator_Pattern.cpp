#include<bits/stdc++.h>
using namespace std;

// base pizza abstract class
class basePizza {
public:
    virtual int cost() = 0;
};

// types of base pizza:
class pizza1: public basePizza {
public:
    int cost() override {
        return 100;
    }
};

// decorator on base pizza: uska abstract class
class toppingPizza: public basePizza {
public:
    virtual int cost() = 0;
};

class extraCheese: public toppingPizza {
    basePizza* p;
public:
    extraCheese(basePizza* p) {
        this -> p = p;
    }
    
    int cost() override {
        return p -> cost() + 10;
    }
};

// decorators
class mushroom: public toppingPizza {
    basePizza* p;
public:
    mushroom(basePizza* p) {
        this -> p = p;
    }
    
    int cost() override {
        return p -> cost() + 20;
    }
};

int main() {
    extraCheese* c = new extraCheese(new pizza1);
    cout << c -> cost() << endl;
    
    // this mushroom pizza is a decorator on extraCheese pizza which is a decorator on base pizza
    mushroom* m = new mushroom(new extraCheese(new pizza1));
    cout << m -> cost() << endl;
}