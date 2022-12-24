#ifndef EXEPTIONFIELD_H
#define EXEPTIONFIELD_H

#include "myexeption.h"
#include "../GameLogic/field.h"
class ExeptionField : public MyExeption
{
public:
    ExeptionField(int h, int w, int count){
        if(h <= 0)what += "bad height "+ std::to_string(h) + "\n";
        if(w <= 0)what += "bad width " + std::to_string(w) + "\n";
        if(count != h * w && h > 0 && w > 0)
            what = "Expected size: " + std::to_string(h * w) + "\nGot " + std::to_string(count) + " cells";
    }
    ExeptionField(int row, int colomn) {
        what = "Bad cell at " + std::to_string(row) + " row, " + std::to_string(colomn) + "column";
    }
    ExeptionField(int win, int key, bool b) {
        what = "bad count for win position " + std::to_string(win) +
                "bad count for count key " + std::to_string(key) +
                "field size default";
    }
    ExeptionField(int size, bool is){
        if(is) what = "Found mark, didn't found cells " + std::to_string(size);
        else what = "didn't found marks for field";
    }
    std::string what_() override {return what;}
};

#endif // EXEPTIONFIELD_H
