#ifndef CELLVIEW_H
#define CELLVIEW_H
#include "../GameLogic/cell.h"
#include "qtablewidget.h"
class CellView
{
public:
    CellView() = default;
    QTableWidgetItem * drowNewCell(const Cell & cell, const Position & playerPosition);
    void drowCell(QTableWidgetItem * item, const Cell & cell, const Position & playerPosition);
    std::string toString(const Cell & cell) {
        return (cell.getIsOpen() ? std::to_string(1) : std::to_string(0)) + std::to_string(getType(cell.getEvent()));
    }
private:
    void setItem(int numType, bool isOpen, QTableWidgetItem * item);
    int getType(Event * event);
};

#endif // CELLVIEW_H
