#include "dataparser.h"
#include "Events/EventField/eventwin.h"
#include "Events/EventField/eventunlock.h"
#include "Events/EventField/eventlock.h"
#include "Events/EventPlayer/eventnone.h"
#include "Events/EventPlayer/eventadd.h"
#include "Events/EventPlayer/eventkey.h"
#include <string.h>
#include "Exeptions/exeptionfield.h"
#include "Exeptions/exeptionfile.h"
#include "Exeptions/exeptionplayer.h"
#include "hasher.h"

bool isNumber(std::string s) {
    if(s.length() == 0)return false;
    for(int i = 0; i < s.length(); i++) {
        if(!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void DataParser::parseField(std::vector<std::string> &data, int &level, Field &field, Player * player)
{
    if(data.empty())throw(ExeptionFile(false));
    //if(!Hasher().check_hash(data))throw(ExeptionFile(false));
    int h = -1;
    int w = -1;
    int index_of_field_bein = 0;
    int index_of_field_end = -1;
    int positionPlayer = -1;
    int tmp_ = 0;
    if(data.size() > 0 && isNumber(data[0])) {
        level = stoi(data[0]);
    } else {
        level = 0;
    }
    while(tmp_ < data.size() && (index_of_field_end == -1 || h == -1 || w == -1 || positionPlayer == -1)) {
        if(data[tmp_] == "FS:" && tmp_ + 2 < data.size()
                && isNumber(data[tmp_ + 1]) && isNumber(data[tmp_ + 2])) {
            index_of_field_bein = tmp_;
            h = stoi(data[tmp_ + 1]);
            w = stoi(data[tmp_ + 2]);
        }
        if(data[tmp_] == ":FE")
            index_of_field_end = tmp_;
        if(data[tmp_] == "HPPOS:")
            positionPlayer = tmp_;
        tmp_++;
    }
    index_of_field_bein +=3;
    if(h <= 0 || w <= 0 || index_of_field_end - index_of_field_bein != h * w)
        throw(ExeptionField(h, w, index_of_field_bein - index_of_field_end));

    try{
        check(data, index_of_field_bein, h, w);
        fillField(data, field, index_of_field_bein, h, w);
    } catch(ExeptionField &e) {
        std::cout<<e.what_()<<std::endl;
    }
    if(data.size() >= positionPlayer + 5 && positionPlayer != -1) {
        int x = -1, y = -1, healt = -1;
        if(isNumber(data[positionPlayer + 1]) && stoi(data[positionPlayer + 1]) >= 0 && stoi(data[positionPlayer + 1]) < h) x = stoi(data[positionPlayer + 1]);
        if(isNumber(data[positionPlayer + 2]) && stoi(data[positionPlayer + 2]) >= 0 && stoi(data[positionPlayer + 2]) < w) y = stoi(data[positionPlayer + 2]);
        if(isNumber(data[positionPlayer + 3]) && stoi(data[positionPlayer + 3]) >= 0 && stoi(data[positionPlayer + 3]) < 100) healt = stoi(data[positionPlayer + 3]);
        if(x != -1 && y != -1 && x < h && y < w) {
            field.setStartPosition(Position(x,y));
            player->startNew(Position(x,y));
        } else {throw(ExeptionPlayer(x, y));}
        if(healt != -1) player->setHealth(healt);
            else player->setHealth(100);
    } else {
        throw(ExeptionPlayer(data.size() - positionPlayer - 5));
    }
    if(!Hasher().check_hash(data))throw(ExeptionFile(false));
}

void DataParser::check(std::vector<std::string> &data, int i, int h, int w){
    int win_count = 0;
    int key_count = 0;
    for(int stl = 0; stl < h; stl++) {
        for(int str = 0; str < w; str++) {
            if(!isNumber(data[i + stl*w + str].substr(1)))
                throw(ExeptionField(stl,str));
            if(stoi((data[i + stl*w + str].substr(1))) == 15)key_count++;
            if(stoi((data[i + stl*w + str].substr(1))) == 10)win_count++;
        }
     }
    if(win_count != 1 || key_count != 1)throw(ExeptionField(win_count, key_count, true));
}

void DataParser::fillField(std::vector<std::string> &data, Field &field, int i, int h, int w)
{
    field = Field(h,w);
    for(int stl = 0; stl < h; stl++) {
        for(int str = 0; str < w; str++) {
            if(isNumber(data[i + stl*w + str])){
                if(data[i + stl*w + str][0] == '0')
                    field.lockCell(stl, str);
                int type = -1;
                if(isNumber(data[i + stl*w + str].substr(1)))
                    type = stoi(data[i + stl*w + str].substr(1));
                switch (type) {
                    case 0:
                        field.setNewEvent(new EventNone(), stl, str);
                        break;
                    case 1:
                        field.setNewEvent(new EventAdd(), stl, str);
                        break;
                    case 3:
                        field.setNewEvent(new EventLock(), stl, str);
                        break;
                    case 4:
                        field.setNewEvent(new EventUnlock(), stl, str);
                        break;
                    case 10:
                        field.setNewEvent(new EventWin(), stl, str);
                        field.setPositionWin(stl,str);
                        break;
                    case 15:
                        field.setNewEvent(new EventKey(), stl, str);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
}

