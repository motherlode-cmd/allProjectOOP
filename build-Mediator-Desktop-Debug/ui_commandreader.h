/********************************************************************************
** Form generated from reading UI file 'commandreader.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDREADER_H
#define UI_COMMANDREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandReader
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QPushButton *up;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QProgressBar *progressBar;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_logger;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QCheckBox *checkBox_info;
    QCheckBox *checkBox_state;
    QCheckBox *checkBox_Error;
    QGraphicsView *graphicsView;
    QPushButton *Saver;
    QPushButton *load;
    QLineEdit *fileName;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CommandReader)
    {
        if (CommandReader->objectName().isEmpty())
            CommandReader->setObjectName(QString::fromUtf8("CommandReader"));
        CommandReader->resize(800, 600);
        centralwidget = new QWidget(CommandReader);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 10, 80, 25));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(180, 110, 381, 321));
        tableWidget->setMouseTracking(false);
        tableWidget->setTabletTracking(false);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(true);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setDragDropOverwriteMode(true);
        tableWidget->setShowGrid(true);
        tableWidget->setCornerButtonEnabled(true);
        up = new QPushButton(centralwidget);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(90, 470, 40, 40));
        left = new QPushButton(centralwidget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(130, 510, 40, 40));
        right = new QPushButton(centralwidget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(50, 510, 40, 40));
        down = new QPushButton(centralwidget);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(90, 510, 40, 40));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(600, 80, 118, 23));
        progressBar->setValue(24);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 50, 80, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 30, 80, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 440, 291, 151));
        pushButton_logger = new QPushButton(centralwidget);
        pushButton_logger->setObjectName(QString::fromUtf8("pushButton_logger"));
        pushButton_logger->setGeometry(QRect(160, 30, 80, 25));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(400, 10, 42, 26));
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(400, 40, 42, 26));
        checkBox_info = new QCheckBox(centralwidget);
        checkBox_info->setObjectName(QString::fromUtf8("checkBox_info"));
        checkBox_info->setGeometry(QRect(20, 10, 77, 23));
        checkBox_state = new QCheckBox(centralwidget);
        checkBox_state->setObjectName(QString::fromUtf8("checkBox_state"));
        checkBox_state->setGeometry(QRect(20, 30, 77, 23));
        checkBox_Error = new QCheckBox(centralwidget);
        checkBox_Error->setObjectName(QString::fromUtf8("checkBox_Error"));
        checkBox_Error->setGeometry(QRect(20, 50, 77, 23));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(420, 110, 371, 311));
        Saver = new QPushButton(centralwidget);
        Saver->setObjectName(QString::fromUtf8("Saver"));
        Saver->setGeometry(QRect(620, 10, 80, 25));
        load = new QPushButton(centralwidget);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(710, 10, 80, 25));
        fileName = new QLineEdit(centralwidget);
        fileName->setObjectName(QString::fromUtf8("fileName"));
        fileName->setGeometry(QRect(650, 40, 113, 25));
        CommandReader->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CommandReader);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        CommandReader->setMenuBar(menubar);
        statusbar = new QStatusBar(CommandReader);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CommandReader->setStatusBar(statusbar);

        retranslateUi(CommandReader);

        QMetaObject::connectSlotsByName(CommandReader);
    } // setupUi

    void retranslateUi(QMainWindow *CommandReader)
    {
        CommandReader->setWindowTitle(QCoreApplication::translate("CommandReader", "CommandReader", nullptr));
        pushButton->setText(QCoreApplication::translate("CommandReader", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        up->setText(QCoreApplication::translate("CommandReader", "^", nullptr));
        left->setText(QCoreApplication::translate("CommandReader", "->", nullptr));
        right->setText(QCoreApplication::translate("CommandReader", "<-", nullptr));
        down->setText(QCoreApplication::translate("CommandReader", "down", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CommandReader", "Level : ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CommandReader", "\321\201\321\211\320\267\320\275", nullptr));
        label->setText(QCoreApplication::translate("CommandReader", "TextLabel", nullptr));
        pushButton_logger->setText(QCoreApplication::translate("CommandReader", "Log", nullptr));
        checkBox_info->setText(QCoreApplication::translate("CommandReader", "Info", nullptr));
        checkBox_state->setText(QCoreApplication::translate("CommandReader", "State", nullptr));
        checkBox_Error->setText(QCoreApplication::translate("CommandReader", "Error", nullptr));
        Saver->setText(QCoreApplication::translate("CommandReader", "save", nullptr));
        load->setText(QCoreApplication::translate("CommandReader", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandReader: public Ui_CommandReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDREADER_H
