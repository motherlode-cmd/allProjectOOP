#ifndef PLAYERPOSITIONROOL_H
#define PLAYERPOSITIONROOL_H

#include "GameLogic/Player.h"
#include "GameLogic/field.h"
template <int r>
class PlayerPositionRool
{
public:
    PlayerPositionRool(){}
    //PlayerPositionRool<Player * >();

    static void fill(Field &field, Player * player)
    {
        int h = field.getHeight();
        int w = field.getWidth();
        int i = 0, j = 0;
        while(i < h && j < w) {
            if(field.isOpen(i,j)) {
                field.setStartPosition(Position(i,j));
                player->startNew(field.getPositionPlayer());
                field.openCell(i, j);
                return;
            }
            else {
                i++;
                j++;
            }
        }
    }
};

#endif // PLAYERPOSITIONROOL_H
