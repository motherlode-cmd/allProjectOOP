#ifndef UNLOCKROOLS_H
#define UNLOCKROOLS_H
#include "RulesVectors.h"
#include "GameLogic/field.h"
template <int r>
class UnlockCellRool
{
public:
    UnlockCellRool(){}
    static void fill(Field & field, Player * player)
    {
        int h = field.getHeight();
        int w = field.getWidth();
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(abs(randomLock[(r + i + j) % randomLock.size()]) % 5 == 0)
                    field.unlockCell(i,j);
            }
        }
    }

};
#endif // UNLOCKROOLS_H
