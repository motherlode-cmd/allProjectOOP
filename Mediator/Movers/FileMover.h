#ifndef FILEMOVER_H
#define FILEMOVER_H
#include "AbstractMove.h"
#include "qevent.h"
class FileMover : public AbstractMove
{
public:
    FileMover(std::string filename);
    ~FileMover(){}
    void setMove(QKeyEvent * key) {
        if(up == (key->text()).toStdString()) {
                x = -1;
                y = 0;
        } else if(down == (key->text()).toStdString()) {
            x = 1;
            y = 0;
        } else if(left == (key->text()).toStdString()) {
            x = 0;
            y = -1;
        } else if(right == (key->text()).toStdString()) {
            x = 0;
            y = 1;
        } else if((key->text()).toStdString() != right && (key->text()).toStdString() != up
                && (key->text()).toStdString() != left && (key->text()).toStdString() != down){
            x = 0;
            y = 0;
        }
    }
    const Position getMove() const override;
private:
    int x = 0;
    int y = 0;
    std::string up;
    std::string down;
    std::string left;
    std::string right;
};

#endif // FILEMOVER_H
