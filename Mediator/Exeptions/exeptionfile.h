#ifndef EXEPTIONFILE_H
#define EXEPTIONFILE_H
#include "myexeption.h"
class ExeptionFile : MyExeption
{
public:
    ExeptionFile(std::string file_name){
        if(file_name.length() == 0)
            what = "Empty file name";
        else
            what = "Bad file name" + file_name + " can't open this";
    }
    ExeptionFile(bool e) {
        if(!e)
            what = "File was changed";
    }
    std::string what_() override {return what;}
};

#endif // EXEPTIONFILE_H
