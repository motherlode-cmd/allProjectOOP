#include "controller.h"
#include "./Logger/filelogger.h"
#include "Exeptions/exeptionfield.h"
#include "Exeptions/exeptionplayer.h"
#include "GameLogic/Rools/KeyRool.h"
#include "GameLogic/Rools/UnlockRools.h"
#include "GameLogic/Rools/WinRool.h"
#include "GameLogic/Rools/eventrool.h"
#include "GameLogic/Rools/lockcellrool.h"
#include "GameLogic/Rools/playerpositionrool.h"
#include "GameLogic/generaterools.h"
#include "humanPlayer.h"
#include <fstream>
#include "Logger/consolelogger.h"
//#include "generatelevel.h"
#include "./Observer/loggerobserver.h"

Controller::Controller()
{
    player = new HumanPlayer();
    obs = new LoggerObserver();
    obs->addLogger(new ConsoleLogger());
    FileLogger * ofs = new FileLogger("../Mediator/newTest.txt");
    obs->addLogger(ofs);
    field.setObs(obs);
    player->setObs(obs);
}

Controller::~Controller()
{
    obs->update(Level::Info,"Exit game");
    delete obs;
    delete player;
}

void Controller::start(QTableWidget * table, QGraphicsScene * sc, int n, int m)
{
    started = true;
    state = 1;
    field = Field(n + level, m + level);
    fieldView = FieldView(field, table, sc);
    if(n > 0 && m > 0){
        obs->update(Level::Info,"Started new game");
        nextLevel(table, sc);
    } else {
        obs->update(Level::Error,"invalid size for field");
    }
}


void Controller::makeMove(QTableWidget * table, QGraphicsScene * sc, int x, int y)
{
    try {
        if(field.getHeight() > 0 && field.getWidth() > 0) {
            field.playerMove(x, y, player);
            checkState();
            fieldView.drowField(field, table, sc);
        } else {
            throw(field.getHeight());
        }
    } catch(int a) {
        obs->update(Level::Error, "Invalid Game, can't move");
    }
}

int Controller::getPlayerHealth()
{
    return player->getHealth();
}

QString Controller::currentState()
{
    return QString::number(player->getCurrentPosition().getX()) + " " + QString::number(player->getCurrentPosition().getY());
}

int Controller::getState() const
{
    return state;
}

void Controller::checkState()
{
    if(player->keyState()) {
        field.unlockWin();
    }
    if(field.isWin()) {
        state = 2;
        level++;
        started = false;
        field = Field(0,0);
    }
    if(player->getHealth() == 0){
        state = 0;
        level = 0;
        started = 0;
        field = Field(0,0);
    }
}

void Controller::nextLevel(QTableWidget * table, QGraphicsScene *sc)
{
    if(field.getHeight() > 0 && field.getWidth() > 0) {
        if( level % 2 == 0) {
            GenerateRools <LockCellRool<1>, UnlockCellRool<1>, PlayerPositionRool<1>, EventRool<1>, WinRool<1>, KeyRool<1> > g;
            field = g.generate(field, player);
            fieldView.drowField(field, table, sc);
        } else if(level % 2 == 1) {
            GenerateRools <LockCellRool<2>, UnlockCellRool<2>, PlayerPositionRool<2>, EventRool<2>, WinRool<2>, KeyRool<2>> g;
            field = g.generate(field, player);
            fieldView.drowField(field, table, sc);
        }
    }
}

bool Controller::getStarted() const
{
    return started;
}

void Controller::deleteLevel(Level level)
{
    obs->deleteLevel(level);
}

void Controller::serialization(std::string fileName)
{
    Seriallisation <FieldView, Player> s;
    fieldView.toString(field);
    try {
        s.write(fileName, level, fieldView, *player);
    } catch(ExeptionFile & e) {
        std::cout<<e.what_()<<std::endl;
    }
}

Position Controller::load(QTableWidget *t, QGraphicsScene *sc, std::string fileName)
{
    //"testSer.bin"
    Seriallisation <FieldView, Player> s;
    try{
        s.load(fileName, level, field, player);
    } catch(ExeptionFile & e) {
        std::cout<<e.what_()<<std::endl;
    } catch(ExeptionField & ef) {
        std::cout<<ef.what_()<<std::endl;
    } catch(ExeptionPlayer & ef) {
        std::cout<<ef.what_()<<std::endl;
    }
    fieldView = FieldView(field, t, sc);
    started = true;
    state = 1;
    return Position(field.getHeight() - level, field.getWidth() - level);
}


void Controller::addLevel(Level level)
{
    obs->addLevel(level);
}


