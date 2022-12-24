#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../Views/fieldview.h"
#include "GameLogic/humanPlayer.h"
//#include "generatelevel.h"
#include <QObject>
#include "../seriallisation.h"
#include "Player.h"
class Controller
{
public:
    Controller();
    ~Controller();
    void start(QTableWidget * table, QGraphicsScene * sc, int n = 3, int m = 3/*, std::vector <Logger *> & svec*/);
    void makeMove(QTableWidget * table, QGraphicsScene * sc, int x, int y);
    int getPlayerHealth();
    QString currentState();
    //std::string insert(const std::string& str, char s);
    int getState() const;
    bool getStarted() const;
    void addLevel(Level level);
    void deleteLevel(Level level);
    Observer * getObserver(){return obs;}
    void serialization(std::string fileName);
    Position load(QTableWidget * t, QGraphicsScene *sc, std::string fileName);

signals:
    void signal();
private:
    void ntfLggs();
    void checkState();
    void nextLevel(QTableWidget *table, QGraphicsScene * sc);
    FieldView fieldView;
    Player * player;
    Field field;
    int state = 1;
    int level = 0;
    bool started = false;
    //GenerateLevel generateLevel;
    Observer * obs;
    //std::vector <Logger *> loggers;
};

#endif // CONTROLLER_H
