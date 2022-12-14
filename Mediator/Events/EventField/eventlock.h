#ifndef EVENTLOCK_H
#define EVENTLOCK_H
#include "eventField.h"

class EventLock : public EventField
{
public:
    EventLock(){}
    ~EventLock(){}
    void newField(Field & field) override;
    std::string print() const override {return "Locked cell " ;}
    EventLock * clone() override{
        return new EventLock();
    }

};

#endif // EVENTLOCK_H
