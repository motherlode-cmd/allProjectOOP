#include "humanPlayer.h"
#include <iostream>
HumanPlayer::HumanPlayer(const Position & position)
{
    currentPosition = position;
    health = 100;
}

HumanPlayer::HumanPlayer(HumanPlayer const &newPlayer)
{
    currentPosition = newPlayer.currentPosition;
    health = newPlayer.health;
    key = newPlayer.key;
}

HumanPlayer &HumanPlayer::operator = (const HumanPlayer &other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
        key = other.key;
    }
    return *this;
}

HumanPlayer &HumanPlayer::operator = (HumanPlayer &&other)
{
    if(this != &other) {
        currentPosition = other.currentPosition;
        health = other.health;
        key = other.key;
        other.health = 0;
    }
    return *this;
}

HumanPlayer::HumanPlayer(HumanPlayer &&source)
{
    currentPosition = source.currentPosition;
    health = source.health;
    key = source.key;
    source.health = 0;
}

void HumanPlayer::makeMove(const Position & newPosition)
{
    try {
        if(currentPosition.getX() >= 0 && currentPosition.getY() >= 0)
            currentPosition = newPosition;
        else
            throw(currentPosition);
    } catch (Position pos){
        notify(Level::Error, "Player invalid");
    }
}

int HumanPlayer::getHealth()
{
    return health;
}

void HumanPlayer::setHealth(int newHealth)
{
    if(health != newHealth) {
        if(obs != nullptr)
            notify(Level::State, "New Player's health is " + std::to_string(newHealth));
    }
    health = newHealth;
    if(health > 100) health = 100;
    if(health < 0) health = 0;
    if(health == 0) {
        notify(Level::State, "----LOSE----");
    }
}

const Position &HumanPlayer::getCurrentPosition() const
{
    return currentPosition;
}

std::string HumanPlayer::printState()
{
    return std::to_string(currentPosition.getX()) + " "+ std::to_string(currentPosition.getY());
}

void HumanPlayer::startNew(const Position &pos)
{
    currentPosition = pos;
    health = 100;
    key = false;
}

