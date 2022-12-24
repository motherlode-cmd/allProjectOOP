#ifndef EVENTKEY_H
#define EVENTKEY_H
#include "eventPlayer.h"
class EventKey : public EventPlayer
{
public:
    EventKey(){}
    ~EventKey(){}
    void makeAction(Player * player) override;
    std::string print() const override {return "in this cell player got Key and cell win is unlocked";}
    EventKey * clone() override{
        return new EventKey();
    }

};

#endif // EVENTKEY_H
