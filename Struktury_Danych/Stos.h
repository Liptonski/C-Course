//
// Created by michal on 08.05.18.
//

#ifndef ROBOCZY2_STOS_H
#define ROBOCZY2_STOS_H

#include <iostream>

template <typename T>

class NodeS {
public:
    T data;
    NodeS *next;
    NodeS(){next = nullptr;}
};

template <typename T>

class Stack {
private:
    NodeS<T> *top;
public:
    Stack():top(nullptr){}
    void push(const T& data);
    T pop();
    void show();
    bool is_empty();
    int size();
    T r_top();
    class Iterator;
    friend class Iterator;
    class Iterator{
        NodeS<T> *s;
    public:
        Iterator(const Stack<T>& st1) : s(st1.top){}
        Iterator(const Iterator& I1) : s(I1.s){};
        Iterator():s(nullptr){}
        NodeS<T> operator++(){
            if(s->next){
                s=s->next;
            }
            else s = nullptr;
            return *s;
        }
        NodeS<T> operator++(int){
            NodeS<T>* x=s;
            if(s->next){
                s=s->next;
            }
            else s= nullptr;
            return *x;
        }
        bool operator == (const Iterator&)const{
            return s==0;
        }
        bool operator != (const Iterator&)const{
            return s!=0;
        }
        T operator*() const{
            if(!s) return 0;
            return s->data;
        }
        Iterator begin() const {return Iterator(*this);}
        Iterator end() const {return Iterator();}
    };
};

template<typename T>
void Stack<T>::push(const T& data) {
    NodeS<T> *el = new NodeS<T>;
    el->data = data;
    if(top== nullptr){
        top=el;
    }
    else{
        el->next = top;
        top = el;
    }
}

template<typename T>
T Stack<T>::pop() {
    int help;
    if(!top) return 0;
    else{
        NodeS<T> *ptr = top->next;
        help = top->data;
        delete top;
        top=ptr;
        return help;
    }
}

template <typename T>
void Stack<T>::show() {
    NodeS<T> *ptr = top;
    if(!ptr){std::cout << "Stos jest pusty" << std::endl; return;}
    while(ptr){
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

template <typename T>
bool Stack<T>::is_empty() {
    if(!top) return true;
    else return false;
}

template <typename T>
int Stack<T>::size() {
    NodeS<T> *ptr = top;
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}

template <typename T>
T Stack<T>::r_top() {
    if(!top) return 0;
    else return top;
}

#endif //ROBOCZY2_STOS_H
