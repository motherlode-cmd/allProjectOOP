#include "uimover.h"

void UIMover::setMove(int x, int y)
{
    this->x = x;
    this->y = y;
}

const Position UIMover::getMove() const
{
    return Position(x,y);
}
