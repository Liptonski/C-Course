#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <math.h>
#include <cassert>

class X{
public:
    X(){}
    int i;
    void foo(int a) const {
        const_cast<X*>(this)->i=a;
    }
};

struct Y{
    int tab[1024];
};

std::set<int, std::greater<> > s;
std::vector<int> v;
class Cmp{
public:
    bool operator()(const std::pair<double, double>& a, const std::pair<double, double>& b) const{
        //assert();
        if((a.first)*(a.first)+(a.second)*(a.second)<(b.first)*(b.first)+(b.second)*(b.second))
            return true;
        if((a.first)*(a.first)+(a.second)*(a.second)>(b.first)*(b.first)+(b.second)*(b.second))
            return false;
        else if (a.first<b.first) return true;
        else if (a.first>b.first) return false;
        return a.second<b.second;
    }
};

class D{
public:
    int a;
    int b;
    D(){}
    D(int aa, int bb): a(aa), b(bb){}
    virtual ~D(){}
};

class Bad : public D{
public:
    Bad(){}
    virtual ~Bad(){};
};

class C{
public:
    C(){}
};

const double* z;

int main() {
    Bad d;
    Bad &bp = d;
    D &dp = dynamic_cast<D&>(bp);
    for(auto i=0; i<10; i++){
        std::cout << sizeof(i) <<std::endl;
    }
    std::cout << typeid(d).name() << std::endl;
    std::cout << typeid(bp).name() << std::endl;
    std::cout << typeid(dp).name() << std::endl;

    return 0;
}