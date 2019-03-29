//
// Created by michal on 07.05.18.
//

#ifndef ROBOCZY2_LISTA_JEDNO_H
#define ROBOCZY2_LISTA_JEDNO_H

#include <iostream>

template <typename T>

class Node {
public:
    T data;
    Node *next;
    Node(){next = nullptr;}
};

template <typename T>

class List {
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr_index;
public:
    List(){head = nullptr; tail= nullptr; curr_index= nullptr;}
    void push_back(const T& data);
    T pop_back();
    void clear();
    void show();
    T front();
    T next();
    int size();
    int operator ==(const List<T>& OList);
    int operator !=(const List<T>& OList);
    class Iterator;
    friend class Iterator;
    class Iterator{
        Node<T> *l;
    public:
        Iterator(const List<T>& st1) : l(st1.head){}
        Iterator(const Iterator& I1) : l(I1.l){};
        Iterator():l(nullptr){}
        Node<T> operator++(){
            if(l->next){
                l=l->next;
            }
            else l = nullptr;
            return *l;
        }
        Node<T> operator++(int){
            Node<T>* x=l;
            if(l->next){
                l=l->next;
            }
            else l= nullptr;
            return *x;
        }
        bool operator == (const Iterator&)const{
            return l==0;
        }
        bool operator != (const Iterator&)const{
            return l!=0;
        }
        T operator*() const{
            if(!l) return 0;
            return l->data;
        }
        Iterator begin() const {return Iterator(*this);}
        Iterator end() const {return Iterator();}
    };
};

class ListInt : public List<int>{
public:
    class Iterator {
        List<int> &Lista;
    public:
        int& operator *();
        Iterator& operator ++();//tak zeby lista nie zapamietywala miejsca a dane brac z noda
        Iterator&operator ++(int);
    };
};

template <typename T>
void List<T>::push_back(const T& data) {
    Node<T> *el = new Node<T>;
    el->data=data;
    if(head == nullptr){
        head=el;
        tail=el;
        curr_index=el;
    }
    else{
        tail->next = el;
        el->next = nullptr;
        tail=el;
    }
}

template <typename T>
void List<T>::show() {
    Node<T> *ptr = head;
    if(!ptr){std::cout << "lista jest pusta" << std::endl; return;}
    while(ptr){
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

template <typename T>
T List<T>::pop_back() {
    Node<T> *ptr = head;
    T tmp;
    if(ptr == nullptr){
        return 0;
    }
    else if(ptr->next == nullptr){
        tmp = ptr->data;
        head = nullptr;
        tail = nullptr;
        curr_index= nullptr;
        delete ptr;
        return tmp;
    }
    else {
        while (ptr->next->next) {
            ptr = ptr->next;
        }
        tmp = ptr->next->data;
        delete ptr->next;
        tail = ptr;
        tail->next = nullptr;
        return tmp;
    }
}

template <typename T>
T List<T>::front() {
    if(head == nullptr){
        return 0;
    }
    else{
        return head->data;
    }
}

template <typename T>
T List<T>::next() {
    if(curr_index == nullptr || curr_index->next == nullptr){return 0;}
    else{
        curr_index = curr_index->next;
        return curr_index->data;
    }
}

template <typename T>
int List<T>::size() {
    int c=0;
    Node<T> *ptr = head;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}

template <typename T>
void List<T>::clear() {
    Node<T> *ptr = head;
    while(ptr){
        delete head;
        head=ptr->next;
        ptr = head;
    }
}

template <typename T>
int List<T>::operator ==(const List<T>& OList){
    Node<T> *ptr1 = head;
    Node<T> *ptr2 = OList.head;
    while(ptr1 && ptr2){
        if(ptr1->data != ptr2->data) return 0;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return 1;
}

template <typename T>
int List<T>::operator !=(const List<T>& OList){
    Node<T> *ptr1 = head;
    Node<T> *ptr2 = OList.head;
    while(ptr1 && ptr2){
        if(ptr1->data == ptr2->data) return 0;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return 1;
}

#endif //ROBOCZY2_LISTA_JEDNO_H
