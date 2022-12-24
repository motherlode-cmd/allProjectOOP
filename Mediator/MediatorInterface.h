#ifndef MEDIATORINTERFACE_H
#define MEDIATORINTERFACE_H
#include "./Movers/AbstractMove.h"
#include "Observer/Observer.h"
#include "QObject"
#include "qgraphicsscene.h"
class MediatorInterface : public QObject {
public:
    virtual ~MediatorInterface(){}
    virtual void startGame( int x, int y) = 0;
    virtual void makeMove(const AbstractMove * m) = 0;
    virtual int getPlayerHealth() = 0;
    virtual Observer * getObserver() = 0;
    virtual void addLevel(Level level) = 0;
    virtual void deleteLevel(Level level) = 0;
    virtual void save(std::string fileName) = 0;
    virtual void load(std::string fileName) = 0;
protected:
    virtual void statusGame(int val) = 0;
};
#endif // MEDIATORINTERFACE_H
