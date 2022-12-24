#ifndef EXEPTIONPLAYER_H
#define EXEPTIONPLAYER_H

#include "myexeption.h"

class ExeptionPlayer : public MyExeption
{
public:
    ExeptionPlayer(int x, int y){
        what = "Bad position for player "+ std::to_string(x) + " " + std::to_string(y);
    }
    ExeptionPlayer(int c) {
        what = "Bad info player expexted 3, got "+std::to_string(3 - c);
    }
    std::string what_() override {return what;}
};

#endif // EXEPTIONPLAYER_H
