#include "FileMover.h"
#include "../jsonservise.h"

FileMover::FileMover(std::string filename)
{
    std::map<std::string, std::string> data = JsonServise().parseData(filename);
    up = data["up"];
    down = data["down"];
    left = data["left"];
    right = data["right"];

}

const Position FileMover::getMove() const
{
    return Position(x,y);
}
