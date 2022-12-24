#ifndef KEYROOL_H
#define KEYROOL_H
#include "RulesVectors.h"
#include "Events/EventPlayer/eventkey.h"
#include "GameLogic/field.h"
//классы авил - шаблонные
template <int h>
class KeyRool
{
public:
    static void fill(Field & field, Player * player)
    {
        int xKey = randomEvent[3] % field.getHeight();
        int yKey = randomEvent[4] % field.getWidth();
        field.setNewEvent(new EventKey, xKey, yKey);
        field.unlockCell(xKey, yKey);
        field.openCell(xKey, yKey);
    }
};
#endif // KEYROOL_H
