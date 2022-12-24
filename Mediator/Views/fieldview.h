#ifndef FIELDVIEW_H
#define FIELDVIEW_H
#include "cellview.h"
#include "../GameLogic/field.h"
#include "qgraphicsscene.h"
#include "qtablewidget.h"
#include <QOpenGLWidget>
#include <QtGui>

class FieldView
{
    //Q_OBJECT
public:
    std::string toString(){return state;}
    FieldView() = default;
    FieldView(const Field &field, QTableWidget * table, QGraphicsScene * sc);
    FieldView(FieldView const & newFieldView);
    FieldView(FieldView && newFieldView);
    FieldView & operator = (const FieldView &other);
    FieldView & operator = (FieldView &&other);
    ~FieldView();
    void drowField(Field & field, QTableWidget * table, QGraphicsScene * sc);
    void drowScene(Field & field, QGraphicsScene * sc);
    void toString(const Field &field);
private:
    //Field field;
    CellView cellView;
    std::string state = "";
    //QGraphicsScene * sc = new QGraphicsScene;
};

#endif // FIELDVIEW_H
