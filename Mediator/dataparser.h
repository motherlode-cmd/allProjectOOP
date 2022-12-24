#ifndef DATAPARSER_H
#define DATAPARSER_H
#include <vector>
#include "GameLogic/field.h"
class DataParser
{
public:
    DataParser() = default;
    void parseField(std::vector <std::string> &data, int & level, Field & field, Player *player);
private:
    void check(std::vector <std::string> &data, int i, int h, int w);
    void fillField(std::vector <std::string> &data, Field & field, int i, int h, int w);
};

#endif // DATAPARSER_H
