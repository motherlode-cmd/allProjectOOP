#ifndef PLAYER_H
#define PLAYER_H
#include "../Observable/gamesubject.h"
#include "position.h"
class Player: public GameSubject
{
public:
    virtual ~Player(){}
    virtual void makeMove(const Position &newPosition) = 0;
    virtual int getHealth() = 0;
    virtual void setHealth(int newHealth) = 0;
    virtual const Position &getCurrentPosition() const = 0;
    virtual void gotKey(bool key) = 0;
    virtual bool keyState() = 0;
    virtual std::string printState() {return "Event ";}
    virtual void startNew(const Position & pos) = 0;
    friend std::ostream& operator << (std::ostream &os, Player &rhs) {
        int a = rhs.getHealth();
        os <<"Player's Health after move: "<< a << " ";
        return os;
    }
};
#endif // PLAYER_H
