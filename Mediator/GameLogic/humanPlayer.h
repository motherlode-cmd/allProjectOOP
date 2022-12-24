#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "position.h"
#include "Player.h"
#include <ostream>
class HumanPlayer : public Player
{
public:
    HumanPlayer() = default;
    HumanPlayer(const Position &position);
    HumanPlayer(HumanPlayer const & newPlayer);
    HumanPlayer(HumanPlayer && source);
    HumanPlayer & operator = (const HumanPlayer &other);
    HumanPlayer & operator = (HumanPlayer && other);
    ~HumanPlayer(){}
    void makeMove(const Position &newPosition) override;
    int getHealth() override;
    void setHealth(int newHealth) override;
    const Position &getCurrentPosition() const override;
    void gotKey(bool key) override {this->key = key;}
    bool keyState() override {return key;}
    std::string printState() override;
    void startNew(const Position & pos) override;
    std::string toString() override;
private:
    Position currentPosition = Position(0,0);
    int health = 100;
    bool key = false;
};

#endif // HUMANPLAYER_H
