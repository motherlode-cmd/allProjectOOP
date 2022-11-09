#ifndef UIMOVER_H
#define UIMOVER_H

#include "AbstractMove.h"

class UIMover : public AbstractMove
{
public:
    UIMover() = default;
    ~UIMover(){}
    void setMove(int x, int y);
    const Position getMove() const override;
private:
    int x = 0;
    int y = 0;
};

#endif // UIMOVER_H
