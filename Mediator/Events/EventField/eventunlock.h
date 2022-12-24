#ifndef EVENTUNLOCK_H
#define EVENTUNLOCK_H
#include "eventField.h"

class EventUnlock : public EventField
{
public:
    EventUnlock(){}
    ~EventUnlock(){}
    void newField(Field & field) override;
    //friend std::ostream& operator << (std::ostream &, EventUnlock *);
    std::string print() const override {return "Unlock some cells";}
    EventUnlock * clone() override{
        return new EventUnlock();
    }

};

#endif // EVENTUNLOCK_H
