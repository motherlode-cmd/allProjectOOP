#ifndef LOCKCELLROOL_H
#define LOCKCELLROOL_H

#include "RulesVectors.h"
#include "GameLogic/field.h"
template <int r>
class LockCellRool
{
public:
    LockCellRool(){}
    static void fill(Field & field, Player * player)
    {
        int h = field.getHeight();
        int w = field.getWidth();
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(abs(randomLock[(r + i + j) % randomLock.size()] + 1) % 3 == 0)
                    field.lockCell(i,j);
            }
        }
    }
private:
    int l;
};

#endif // LOCKCELLROOL_H
