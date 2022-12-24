#ifndef EVENTROOL_H
#define EVENTROOL_H
/*Oksana dura*/
#include "GameLogic/field.h"
#include "Events/EventField/eventlock.h"
#include "Events/EventField/eventunlock.h"
#include "Events/EventPlayer/eventadd.h"
#include "Events/EventPlayer/eventnone.h"
#include "RulesVectors.h"
template <int l>
class EventRool
{
public:
    static void fill(Field & field, Player * player)
    {
        int h = field.getHeight();
        int w = field.getWidth();
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                field.setNewEvent(new EventNone, i, j);
            }
        }

        for(int i = 0; i < h; i++) {
            field.setNewEvent(new EventAdd, abs(randomEvent[i % randomEvent.size()]) % h, abs(randomEvent[(i+1)%randomEvent.size()]) % w);
            field.setNewEvent(new EventUnlock, abs(randomEvent[(i+2) % randomEvent.size()]) % h, abs(randomEvent[(i+3)%randomEvent.size()]) % w);
            field.setNewEvent(new EventLock, abs(randomEvent[(i+4)%randomEvent.size()]) % h, abs(randomEvent[(i+5)%randomEvent.size()]) % w);
        }
    }
};

#endif // EVENTROOL_H
