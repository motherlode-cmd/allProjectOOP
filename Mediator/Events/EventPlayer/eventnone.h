#ifndef EVENTNONE_H
#define EVENTNONE_H
#include "eventPlayer.h"

class EventNone : public EventPlayer
{
public:
    EventNone(){}
    ~EventNone(){}
//    friend std::ostream& operator << (std::ostream &, EventNone *);
    void makeAction(Player * player) override;
    std::string print() const override {return "OOOOPS -10 HP";}
    EventNone * clone() override{
        return new EventNone();
    }

};

#endif // EVENTNONE_H
