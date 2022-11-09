#ifndef COMMANDREADER_H
#define COMMANDREADER_H
#include "MediatorInterface.h"
#include "./Movers/FileMover.h"
#include "qtablewidget.h"
#include "./Movers/uimover.h"
#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class CommandReader; }
QT_END_NAMESPACE

class CommandReader : public QMainWindow
{
    Q_OBJECT

public:
    CommandReader(QWidget *parent = nullptr);
    ~CommandReader();
    void addMediator(MediatorInterface * m);

    QTableWidget * get_table();

    void win();

    void lose();

    void setValueHealth(int i);

    void endGame(QPixmap pixmap);

public slots:

    void on_pushButton_clicked();

    void keyPressEvent(QKeyEvent * e);

    void on_up_clicked();

    void on_down_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_pushButton_logger_clicked();

    void on_checkBox_info_stateChanged(int arg1);

    void on_checkBox_state_stateChanged(int arg1);

    void on_checkBox_Error_stateChanged(int arg1);
private:
    void lockButtons(bool l);
    void setup_visual();
    Ui::CommandReader *ui;
    MediatorInterface * mediator = nullptr;
    UIMover * umover = new UIMover();
    FileMover * fmover = new FileMover("../Mediator/settings.json");
};

inline void CommandReader::keyPressEvent(QKeyEvent *e)
{
    //std::cout<<"key"<<std::endl;
    fmover->setMove(e);
    try{
        mediator->makeMove(fmover);
    } catch(...) {

    }
}
#endif // COMMANDREADER_H
