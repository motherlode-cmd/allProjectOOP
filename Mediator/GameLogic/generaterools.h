#ifndef GENERATEROOLS_H
#define GENERATEROOLS_H
#include <algorithm>

#include "GameLogic/field.h"
template <typename ... Rules>
class GenerateRools
{
public:
    Field & generate(Field & field, Player * player) {
        (Rules::fill(field, player), ...);
        return field;
    }
};
#endif // GENERATEROOLS_H
