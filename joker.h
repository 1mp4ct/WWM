#ifndef JOKER_H
#define JOKER_H

#include "frage.h"

class Joker {
public:
    explicit Joker(){}
    double a;
    double b;
    double c;
    double d;

    virtual void evalQuest(frage q) = 0;
};


class FiftyFiftyJoker : public Joker {
public:
    void evalQuest(frage q);
    ~FiftyFiftyJoker() {}

};

class AudJoker : public Joker {
public:
    void evalQuest(frage q);
    ~AudJoker() {}

};

class PhoneJoker : public Joker {
public:
    void evalQuest(frage q);
    ~PhoneJoker() {}

};

#endif // JOKER_H
