#ifndef ABSTRACTMOVE_H
#define ABSTRACTMOVE_H
#include "../GameLogic/position.h"
class AbstractMove{
public:
    virtual ~AbstractMove(){}
    virtual const Position getMove() const = 0;
};
#endif // ABSTRACTMOVE_H
