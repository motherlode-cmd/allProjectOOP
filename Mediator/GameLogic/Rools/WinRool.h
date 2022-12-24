#ifndef WINROOL_H
#define WINROOL_H
#include "Events/EventField/eventwin.h"
#include "GameLogic/field.h"
#include "RulesVectors.h"
template <int r>
class WinRool
{
public:
    static void fill(Field & field, Player * player)
    {
        int h = field.getHeight();
        int w = field.getWidth();
        int xWin = randomEvent[1] % h;
        int yWin = randomEvent[2] % w;
        field.setNewEvent(new EventWin, xWin, yWin);
        field.lockCell(xWin, yWin);
        field.openCell(xWin,yWin);
        field.setPositionWin(xWin, yWin);
    }
};
#endif // WINROOL_H
