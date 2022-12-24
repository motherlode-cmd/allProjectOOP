#ifndef FILEMOVER_H
#define FILEMOVER_H
#include "AbstractMove.h"
#include "qevent.h"
class FileMover : public AbstractMove
{
public:
    FileMover(std::string filename);
    ~FileMover(){}

    void setMove(QKeyEvent * key);
    const Position getMove() const override;
private:
    int x = 0;
    int y = 0;
    std::string up = "u";
    std::string down = "j";
    std::string left = "h";
    std::string right = "k";
};

#endif // FILEMOVER_H
