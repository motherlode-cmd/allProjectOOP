#include "FileMover.h"
#include "../jsonservise.h"
#include <iostream>
/*
    +Обраболтка исключений
    +дефолтные кнопки
    +одинаковые клавимши
*/
FileMover::FileMover(std::string filename)
{
    std::map<std::string, std::string> data = JsonServise().parseData(filename);
    std::string  s[4] = {"up","down","left","right"};
    for(int i = 0; i < 4; i++) {
        if(data[s[i]] != "") {
            for(int j = i+1; j < 4; j++) {
                if(data[s[i]] == data[s[j]] && data[s[i]] != "") {
                    std::cout<<s[i]<< " equal button "<<s[j]<<std::endl;
                    data[s[i]] = "";
                }
            }
        } else {
            std::cout<<"empty button "<<s[i]<<std::endl;
        }
    }
    if(data[s[0]] != "")
        up = data["up"];
    if(data[s[1]] != "")
        down = data["down"];
    if(data[s[2]] != "")
        left = data["left"];
    if(data[s[3]] != "")
        right = data["right"];

    std::cout<<up<<"-"<<down<<"-"<<left<<"-"<<right<<std::endl;
}

void FileMover::setMove(QKeyEvent *key) {
    if(up == (key->text()).toStdString()) {
            x = -1;
            y = 0;
    } else if(down == (key->text()).toStdString()) {
        x = 1;
        y = 0;
    } else if(left == (key->text()).toStdString()) {
        x = 0;
        y = -1;
    } else if(right == (key->text()).toStdString()) {
        x = 0;
        y = 1;
    } else if((key->text()).toStdString() != right && (key->text()).toStdString() != up
            && (key->text()).toStdString() != left && (key->text()).toStdString() != down){
        x = 0;
        y = 0;
    }
}

const Position FileMover::getMove() const
{
    return Position(x,y);
}
