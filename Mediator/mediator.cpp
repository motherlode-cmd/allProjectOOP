#include "mediator.h"
#include <iostream>
Mediator::Mediator(Controller *controller, CommandReader * commandReader)
{
    this->controller = controller;
    this->commandReader = commandReader;
    commandReader->show();
    t = commandReader->get_table();
    sc = commandReader->getScene();
}

Mediator::~Mediator()
{
}

void Mediator::startGame( int x, int y)
{
    controller->start(t,sc,x,y);
    commandReader->setValueHealth(controller->getPlayerHealth());
}


void Mediator::makeMove(const AbstractMove *move)
{
    int x = move->getMove().getX();
    int y = move->getMove().getY();
    try {
        if(controller->getStarted()) {
            controller->makeMove(t,sc,x,y);
            statusGame(controller->getState());
        }
        else
            throw(controller->getStarted());
    } catch(bool is) {
        controller->getObserver()->update(Level::Error, "Game not started");
    }
}

void Mediator::load(std::string fileName)
{
    Position p = controller->load(t, sc, fileName);
    commandReader->setValueHealth(controller->getPlayerHealth());
    commandReader->setSize(p.getX(), p.getY());
}

void Mediator::statusGame(int val)
{
    commandReader->setValueHealth(controller->getPlayerHealth());
    switch (val) {
    case 1:
        return;
    case 2:
        commandReader->win();
        break;
    case 0:
        commandReader->lose();
        break;
    }
}

