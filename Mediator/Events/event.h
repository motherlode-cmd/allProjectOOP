#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <set>
#include "../Observable/gamesubject.h"
class Event : public GameSubject
{
public:
    virtual ~Event(){}
    virtual std::string print() const {return "Event ";}
    friend std::ostream& operator<<(std::ostream& out, const Event & obj){
        out << obj.print();
        return out;
    }
    virtual Event * clone() = 0;
};//    eventAdd->setObs(obs);
//    eventNone->setObs(obs);
//    eventLock->setObs(obs);
//    eventUnlock->setObs(obs);
//    eventWin->setObs(obs);
//    eventKey->setObs(obs);

#endif // EVENT_H
