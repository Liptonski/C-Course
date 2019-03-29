//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_TRZYNASTE_H
#define ROBOCZY_TRZYNASTE_H

#include <iostream>
using namespace std;
class GameBoard {
public:
    GameBoard() { cout << "GameBoard()\n"; }
    GameBoard(const GameBoard&) {
        cout << "GameBoard(const GameBoard&)\n";
    }
    GameBoard& operator=(const GameBoard&) {
        cout << "GameBoard::operator=()\n";
        return *this;
    }
    ~GameBoard() { cout << "~GameBoard()\n"; }
};
class Game {
    GameBoard gb;
public:
    // Default GameBoard constructor called:
    Game() { cout << "Game()\n"; }
    // You must explicitly call the GameBoard
    // copy-constructor or the default constructor
    // is automatically called instead:
    Game(const Game& g) : gb(g.gb) {
        cout << "Game(const Game&)\n";
    }
    Game(int) { cout << "Game(int)\n"; }
    Game& operator=(const Game& g) {
        // You must explicitly call the GameBoard
        // assignment operator or no assignment at
        // all happens for gb!
        gb = g.gb;
        cout << "Game::operator=()\n";
        return *this;
    }
    class Other {}; // Nested class
    // Automatic type conversion:
    operator Other() const {
        cout << "Game::operator Other()\n";
        return Other();
    }
    ~Game() { cout << "~Game()\n"; }
};
class Chess : public Game {
public:
    Chess() {cout << "Chess()\n";}
    ~Chess(){};
    Chess(const Chess& c) : Game(c){ cout << "copy-Chess()\n";}
    Chess& operator=(const Chess& c){
        Game::operator=(c);
        cout << "operator =\n";
        return *this;
    }
};
void f(Game::Other) {}
class Checkers : public Game {
public:
    // Default base-class constructor called:
    Checkers() { cout << "Checkers()\n"; }
    // You must explicitly call the base-class
    // copy constructor or the default constructor
    // will be automatically called instead:
    Checkers(const Checkers& c) : Game(c) {
        cout << "Checkers(const Checkers& c)\n";
    }
    Checkers& operator=(const Checkers& c) {
        // You must explicitly call the base-class
        // version of operator=() or no base-class
        // assignment will happen:
        Game::operator=(c);
        cout << "Checkers::operator=()\n";
        return *this;
    }
};

class Traveler {
    string s;
public:
    Traveler(string ss): s(ss){};
    Traveler(const Traveler& t) : s(t.s){}
    Traveler& operator=(const Traveler& t){
        s=t.s;
        return *this;
    }
    ~Traveler(){};
};

class Pager {
    string s;
public:
    Pager(string ss): s(ss){};
    Pager(const Pager& p) : s(p.s){}
    Pager& operator=(const Pager& p){
        s=p.s;
        return *this;
    }
    ~Pager(){};
};

class BusinessTraveler : public Traveler {
    Pager p;
public:
    BusinessTraveler() : Traveler("proba"), p("próba2"){};
    BusinessTraveler(string s) : Traveler(s), p(s){};
    BusinessTraveler(const BusinessTraveler& b) : p(b.p), Traveler("nie wiem jak inaczej"){}
    BusinessTraveler& operator=(const BusinessTraveler& b){
        p=b.p;
        return *this;
    }
    ~BusinessTraveler(){};
};

#endif //ROBOCZY_TRZYNASTE_H
