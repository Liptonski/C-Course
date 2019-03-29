//
// Created by michal on 08.05.18.
//

#ifndef ROBOCZY2_LISTA_DWU_H
#define ROBOCZY2_LISTA_DWU_H

#include <iostream>

template <typename T>

class Node2 {
public:
    T data;
    Node2 *next;
    Node2 *prev;
    Node2(){next = nullptr; prev = nullptr;}
};

template <typename T>

class List_2 {
private:
    Node2<T> *head;
    Node2<T> *tail;
    Node2<T> *curr_index;
public:
    List_2(){head = nullptr; tail= nullptr; curr_index= nullptr;}
    void push_back(const T& data);
    void push_front(const T& data);
    T pop_back();
    T pop_front();
    void clear();
    void show();
    void show_reverse();
    T front();
    T back();
    T next();
    T prev();
    int size();
    int operator ==(const List_2<T>& OList);
    int operator !=(const List_2<T>& OList);
    class Iterator;
    friend class Iterator;
    class Iterator{
        Node2<T> *l;
    public:
        Iterator(const List_2<T>& st1) : l(st1.head){}
        Iterator(const Iterator& I1) : l(I1.l){};
        Iterator():l(nullptr){}
        Node2<T> operator++(){
            if(l->next){
                l=l->next;
            }
            else l = nullptr;
            return *l;
        }
        Node2<T> operator++(int){
            Node2<T>* x=l;
            if(l->next){
                l=l->next;
            }
            else l= nullptr;
            return *x;
        }
        Node2<T> operator--(){
            if(l->prev){
                l=l->prev;
            }
            else l = nullptr;
            return *l;
        }
        Node2<T> operator--(int){
            Node2<T>* x=l;
            if(l->prev){
                l=l->prev;
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

template <typename T>
void List_2<T>::push_back(const T& data) {
    Node2<T> *el = new Node2<T>;
    el->data=data;
    if(head == nullptr){
        head=el;
        tail=el;
        curr_index=el;
    }
    else{
        tail->next = el;
        el->next = nullptr;
        el->prev = tail;
        tail=el;
    }
}

template <typename T>
void List_2<T>::push_front(const T& data){
    Node2<T> *el = new Node2<T>;
    el->data=data;
    if(tail == nullptr){
        head=el;
        tail=el;
        curr_index=el;
    }
    else{
        head->prev = el;
        el->prev= nullptr;
        el->next= head;
        head = el;
    }
}

template <typename T>
void List_2<T>::show() {
    Node2<T> *ptr = head;
    if(!ptr){std::cout << "lista jest pusta" << std::endl; return;}
    while(ptr){
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

template <typename T>
void List_2<T>::show_reverse(){
    Node2<T> *ptr = tail;
    if(!ptr){std::cout << "lista jest pusta" << std::endl; return;}
    while(ptr){
        std::cout << ptr->data << std::endl;
        ptr = ptr->prev;
    }
}

template <typename T>
T List_2<T>::pop_back() {
    Node2<T> *ptr = tail;
    T tmp;
    if(ptr == nullptr){
        return 0;
    }
    else if(ptr->prev == nullptr){
        tmp = ptr->data;
        head = nullptr;
        tail = nullptr;
        curr_index= nullptr;
        delete ptr;
        return tmp;
    }
    else {
        tmp = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}

template <typename T>
T List_2<T>::pop_front() {
    Node2<T> *ptr = head;
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
        tmp = head->data;
        head = head->next;
        delete head->prev;
        tail->prev = nullptr;
    }
}

template <typename T>
T List_2<T>::front() {
    if(head == nullptr){
        return 0;
    }
    else{
        return head->data;
    }
}

template <typename T>
T List_2<T>::back(){
    if(tail == nullptr){
        return 0;
    }
    else{
        return tail->data;
    }
}

template <typename T>
T List_2<T>::next() {
    if(curr_index == nullptr || curr_index->next == nullptr){return 0;}
    else{
        curr_index = curr_index->next;
        return curr_index->data;
    }
}

template <typename T>
T List_2<T>::prev() {
    if(curr_index == nullptr || curr_index->prev == nullptr){return 0;}
    else{
        curr_index = curr_index->prev;
        return curr_index->data;
    }
}

template <typename T>
int List_2<T>::size() {
    int c=0;
    Node2<T> *ptr = head;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}

template <typename T>
void List_2<T>::clear() {
    Node2<T> *ptr = head;
    while(ptr){
        delete head;
        head=ptr->next;
        ptr = head;
    }
}

template <typename T>
int List_2<T>::operator ==(const List_2<T>& OList){
    Node2<T> *ptr1 = head;
    Node2<T> *ptr2 = OList.head;
    while(ptr1 && ptr2){
        if(ptr1->data != ptr2->data) return 0;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return 1;
}

template <typename T>
int List_2<T>::operator !=(const List_2<T>& OList){
    Node2<T> *ptr1 = head;
    Node2<T> *ptr2 = OList.head;
    while(ptr1 && ptr2){
        if(ptr1->data == ptr2->data) return 0;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return 1;
}


#endif //ROBOCZY2_LISTA_DWU_H
