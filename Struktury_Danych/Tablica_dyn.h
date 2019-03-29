//
// Created by michal on 08.05.18.
//

#ifndef ROBOCZY2_TABLICA_DYN_H
#define ROBOCZY2_TABLICA_DYN_H

#include <iostream>
#include <cstring>

template <typename T>

class Tab {
    int size;
    T *store;
    int curr_size;
public:
    Tab(const int s):size(s), curr_size(0){store=new T[size];}
    ~Tab(){delete []store;}
    void push_back(const T& data);
    T pop_back();
    int t_size();
    T operator [](const int index);
    void print();
    class Iterator;
    friend class Iterator;
    class Iterator{
        T *t;
    public:
        Iterator(const Tab<T>& t1) : t(t1.store){}
        Iterator(const Iterator& I1) : t(I1.t){};
        Iterator():t(nullptr){}
        Iterator & operator++(){
            ++t;
            return *this;
        }
        Iterator & operator++(int){
            t++;
            return *this;
        }
        Iterator & operator--(){
            --t;
            return *this;
        }
        Iterator & operator--(int){
            t--;
            return *this;
        }
        bool operator == (const Iterator& i)const{
            return t==i.t;
        }
        bool operator != (const Iterator& i)const{
            return t!=i.t;
        }
        T operator*() const{
            if(!*t) return 0;
            return *t;
        }
    };
    Iterator begin() const {return Iterator(*this);}
    Iterator end() const {return Iterator(*this);}
};

template <typename T>
void Tab<T>::push_back(const T& data) {
    if (curr_size<size){
        *(store+(curr_size++))=data;
    }
    else{
        T *nstore;
        size++;
        nstore = new T[size];
        for(int i=0; i<size-1; i++){
            nstore[i]=store[i];
        }
        nstore[size-1]=data;
        delete [] store;
        store = new T[size];
        for(int i=0; i<size; i++){
            store[i]=nstore[i];
        }
        delete []nstore;
        curr_size++;
    }
}

template <typename T>
T Tab<T>::pop_back() {
    if(!curr_size){
        return 0;
    }
    T help = store[--curr_size];
    return help;
}

template <typename T>
int Tab<T>::t_size() {
    return curr_size;
}

template <typename T>
T Tab<T>::operator[](int index) {
    if(index<0 || index>curr_size) return 0;
    else{
        return store[index];
    }
}
template <typename T>
void Tab<T>::print() {
    for(int i=0; i<curr_size; i++){
        std::cout << *(store+i) << " ";
    }
}

template <>
class Tab<bool>{
    int size;
    char *store;
    int curr_size;
    bool read(const unsigned int index) const{
        unsigned int byteId = index / 8;
        unsigned int bitId = index % 8;
        unsigned int bitMask = ( 1 << bitId);
        return ((store[byteId] & bitMask) != 0);
    }
    void set(const unsigned int index, bool value) const {
        unsigned int byteId = index / 8;
        unsigned int bitId = index % 8;
        unsigned int bitMask = (value << bitId);
        store[byteId] |= bitMask;
    }
public:
    class BoolIterator;
    friend class BoolIterator;
    class BoolIterator{
        char *t;
        unsigned curr_bit;
    public:
        BoolIterator(const Tab<bool>& t1) : t(t1.store), curr_bit(0){}
        BoolIterator(const Tab<bool>& t1, bool) : t(t1.store + t1.curr_size-1), curr_bit(0){}
        BoolIterator(const BoolIterator& I1) : t(I1.t), curr_bit(0){};
        BoolIterator():t(nullptr), curr_bit(0){}
        BoolIterator & operator++(){
            ++curr_bit;
            if (curr_bit == 8) {
                curr_bit = 0;
                ++t;
            }
            return *this;
        }
        BoolIterator & operator++(int){
            ++curr_bit;
            if (curr_bit == 8) {
                curr_bit = 0;
                t++;
            }
            return *this;
        }
        BoolIterator & operator--(){
            --curr_bit;
            if (curr_bit < 0) {
                curr_bit = 7;
                --t;
            }
            return *this;
        }
        BoolIterator & operator--(int){
            --curr_bit;
            if (curr_bit < 0) {
                curr_bit = 7;
                t--;
            }
            return *this;
        }
        bool operator == (const BoolIterator& bi)const{
            return t==bi.t;
        }
        bool operator != (const BoolIterator& bi)const{
            return t!=bi.t;
        }
        bool operator *() const {return *t & (1<<curr_bit);}

    };
    BoolIterator begin() const {return BoolIterator(*this);}
    BoolIterator end() const {return BoolIterator(*this, true);}

    Tab(const int s):size(s), curr_size(0){
        if ( size > 8 and size%8 != 0) size += 8;
        if (size < 8) size = 8;
        store = new char[sizeof(char) * size / 8];
    }
    ~Tab(){delete []store;}
    void push_back(const bool& data){
        if (curr_size!=size){
            set(++curr_size, data);
        }
        else{
            char *nstore;
            nstore = new char[sizeof(char) * size/8];
            memcpy(nstore, store, size/8);

            delete [] store;
            size += 8;
            store = new char[sizeof(char) * size/8];

            memcpy(store, nstore, size/8);
            delete [] nstore;

            set(++curr_size, data);
        }
    }
    bool pop_back(){return read(--curr_size + 1);}
    int t_size(){return curr_size;}
    bool operator [](const int index){return read(index);}
    void print(){
        for(int i=0; i<curr_size; i++){
            std::cout << *(store+i) << " ";
        }
    }
};

#endif //ROBOCZY2_TABLICA_DYN_H
