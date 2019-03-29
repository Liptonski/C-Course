#include <iostream>
#include "lista_jedno.h"
#include "lista_dwu.h"
#include "Stos.h"
#include "Tablica_dyn.h"


int main(int, char* []) {

    List<int> l;
    List<int> ll;
    ll.push_back(36);
    ll.push_back(90);
    ll.push_back(30);

    l.push_back(25);
    l.push_back(36);
    l.push_back(90);
    l.push_back(30);

    List<int>::Iterator i=l;
    int j=(++i).data;

    int b = l!=ll;
    int x = l.pop_back();
    l.next();
    int y = l.next();
    l.show();
    int z = l.size();
    l.clear();
    l.show();
    std::cout << j << x << " " << y << " " << b << std::endl;*/

    List_2<int> d;
    d.push_front(50);
    d.push_front(60);
    d.push_front(70);
    d.show();
    List_2<int>::Iterator ii = d;
    int x=(++ii).data;
    ii++;
    int y = (--ii).data;
    std::cout << x << " " << y << std::endl;
    d.pop_front();
    d.show();

    std::cout << std::endl;*/

    Stack<int> s;
    s.push(50);
    s.push(40);
    s.push(30);
    s.show();
    int p = s.size();
    s.show();
    bool e = s.is_empty();
    Stack<int>::Iterator it = s;
    for(int i=0; i<1; i++){
        it++;
    }
    int x = (++it).data;
    std::cout << x << " " << e << " " << p << std::endl;
    std::cout <<std::endl;

    Tab<bool> t(5);
    t.push_back(true);
    t.push_back(true);
    t.push_back(false);
    t.push_back(true);
    t.push_back(false);
    t.push_back(true);
    Tab<bool>::BoolIterator it(t);
    int u=t[3];
    for(int i = 0; i<6; i++){
        std::cout << *it++ << std::endl;
    }
    std::cout << u  << std::endl;
    //t.print();
    return 0;
}
