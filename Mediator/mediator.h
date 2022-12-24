#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "./GameLogic/controller.h"
#include "./Movers/AbstractMove.h"
#include "commandreader.h"
#include "MediatorInterface.h"
#include <QObject>
#include <QKeyEvent>
class Mediator : public MediatorInterface
{
public:
    Mediator(Controller * controller, CommandReader * commandReader);
    ~Mediator();
    void startGame( int x, int y) override;
    void makeMove(const AbstractMove * move) override;
    int getPlayerHealth() override {return controller->getPlayerHealth();}
    Observer * getObserver() override {return controller->getObserver();}
    void addLevel(Level level) override {controller->addLevel(level);}
    void deleteLevel(Level level) override {controller->deleteLevel(level);}
    void save(std::string fileName) override {controller->serialization(fileName);}
    void load(std::string fileName) override;
private:
    void statusGame(int val) override;
    Controller * controller;
    CommandReader * commandReader;
    //QOpenGLWidget * field_drow = nullptr;
    QGraphicsScene * sc = nullptr;
    QTableWidget * t = nullptr;
    int a = 0;
};

#endif // MEDIATOR_H
