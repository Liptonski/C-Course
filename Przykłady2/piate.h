//
// Created by michal on 26.04.18.
//

#ifndef ROBOCZY3_PIATE_H
#define ROBOCZY3_PIATE_H

#include <iostream>
using namespace std;
enum note { middleC, Csharp, Cflat }; // Etc.
class Instrument {
public:
    virtual void play(note) const {
        cout << "Instrument::play" << endl;
    }
    virtual void prepare(){};
};
// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
public:
  // Override interface function:
  void play(note) const {
    cout << "Wind::play" << endl;
  }
};
void tune(Instrument& i) {
  // ...
  i.play(middleC);
    i.prepare();
}

#endif //ROBOCZY3_PIATE_H
