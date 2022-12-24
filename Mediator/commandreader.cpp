#include "commandreader.h"
#include "dialog.h"
#include "ui_commandreader.h"
#include "QStandardItem"
#include "QFile"
#include "QList"
#include <QButtonGroup>
CommandReader::CommandReader(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommandReader)
{
    ui->setupUi(this);
    setup_visual();
    connect(this, SIGNAL(signal()), this, SLOT(state()));
    lockButtons(false);
    scene = new QGraphicsScene;
    ui->tableWidget->setTabKeyNavigation(false);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scene->setSceneRect(ui->graphicsView->rect());
    ui->graphicsView->hide();
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //ui->tableWidget->verticalHeader()->setStretchLastSection(true);
    //ui->graphicsView->setSceneRect(0,0,300,300);
    //ui->graphicsView->centerOn(0,0);
    //ui->graphicsView->scene()->addText("grt");
    lockButtons(true);
}

CommandReader::~CommandReader()
{
    delete ui;
    delete fmover;
    delete umover;
}

void CommandReader::addMediator(MediatorInterface * m)
{
    mediator = m;
}

QTableWidget * CommandReader::get_table()
{
    return ui->tableWidget;
}

QGraphicsScene *CommandReader::getScene()
{
    return scene;
}


void CommandReader::on_pushButton_clicked()
{
    setup_visual();
    mediator->startGame(ui->spinBox->value(), ui->spinBox_2->value());
    ui->tableWidget->show();
    lockButtons(true);
}

void CommandReader::win()
{
    //ui->lineEdit->setText("you win");
    QPixmap pix = QPixmap("winner.png");
    endGame(pix);

}

void CommandReader::lose()
{
    QPixmap pix = QPixmap("loser.png");
    //ui->lineEdit->setText("you lose");
    endGame(pix);

}

void CommandReader::setValueHealth(int i)
{
    ui->progressBar->setValue(i);
}

void CommandReader::endGame(QPixmap pixmap)
{
    ui->tableWidget->hide();
    ui->label->show();
    //ui->lineEdit->show();
    pixmap.scaled(700,600);
    ui->label->setPixmap(pixmap);
    ui->pushButton->setText("start new level");
    ui->pushButton->setEnabled(true);
}
void CommandReader::on_up_clicked()
{
    umover->setMove(-1,0);
    mediator->makeMove(umover);
}

void CommandReader::on_down_clicked()
{
    umover->setMove(1,0);
    mediator->makeMove(umover);
}
void CommandReader::on_left_clicked()
{
    umover->setMove(0,1);
    mediator->makeMove(umover);
}


void CommandReader::on_right_clicked()
{
    umover->setMove(0, -1);
    mediator->makeMove(umover);
}

void CommandReader::setup_visual()
{
    //ui->comboBox->hide();
    //ui->lineEdit->hide();
    ui->label->hide();
}

void CommandReader::on_pushButton_logger_clicked()
{
    Dialog dlg;
    dlg.getObs(mediator->getObserver());
    dlg.exec();
}

void CommandReader::lockButtons(bool l)
{
    ui->up->setEnabled(l);
    ui->down->setEnabled(l);
    ui->right->setEnabled(l);
    ui->left->setEnabled(l);
}

void CommandReader::on_checkBox_info_stateChanged(int arg1)
{
    if(arg1 == 0){
        mediator->deleteLevel(Level::Info);
    } else
        mediator->addLevel(Level::Info);
}


void CommandReader::on_checkBox_state_stateChanged(int arg1)
{
    if(arg1 == 0){
        mediator->deleteLevel(Level::State);
    } else
        mediator->addLevel(Level::State);

}


void CommandReader::on_checkBox_Error_stateChanged(int arg1)
{
    if(arg1 == 0){
        mediator->deleteLevel(Level::Error);
    } else
        mediator->addLevel(Level::Error);
}

void CommandReader::setSize(int i, int j)
{
    ui->spinBox->setValue(i);
    ui->spinBox_2->setValue(j);
}

void CommandReader::on_Saver_clicked()
{
    mediator->save((ui->fileName)->text().toStdString());
}


void CommandReader::on_load_clicked()
{
    mediator->load((ui->fileName)->text().toStdString());
}

