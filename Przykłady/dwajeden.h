//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_DWAJEDEN_H
#define ROBOCZY_DWAJEDEN_H

enum note { middleC, Csharp, Cflat }; // Etc.
class Instrument {
public:
  virtual void play(note) const { cout << "cos tam";}
  void prepare() const {}
};
// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
    void play(note) const { cout << "cos innego"; }
};
void tune(Instrument& i) {
  // ...
  i.play(middleC);
  i.prepare();
}


#endif //ROBOCZY_DWAJEDEN_H
