#include "fieldview.h"
#include "qheaderview.h"
#include <QGLColormap>
FieldView::FieldView(const Field & field, QTableWidget * table, QGraphicsScene * sc)
{
    //this->field = field;
    int n = field.getHeight();
    int m = field.getWidth();
    if(n > 0 && m > 0){
        table->setColumnCount(m);
        table->setRowCount(n);
        table->horizontalHeader()->setDefaultSectionSize(50);    // width
        table->verticalHeader()->setDefaultSectionSize(50);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //std::cout<<"drow"<<i<<" "<< j  <<std::endl;
                table->setItem(i,j,cellView.drowNewCell(field.cells[i][j], field.positionPlayer));
            }
        }
    }
    sc->activeWindow();
    QPen pen(QColor(0, 255, 155));
    sc->addLine(100,100,1,1,pen);
    //std::cout<<"ddd"<<std::endl;
}

FieldView::FieldView(const FieldView &newFieldView):/*field(newFieldView.field),*/ cellView(newFieldView.cellView),state(newFieldView.state)
{}

FieldView::FieldView(FieldView &&newFieldView):/*field(newFieldView.field),*/ cellView(newFieldView.cellView),state(newFieldView.state)
{
    //newFieldView.field = Field(0,0);
}

FieldView &FieldView::operator = (const FieldView &other)
{
    if(this != &other) {
        //field = other.field;
        cellView = other.cellView;
        state = other.state;
    }
    return *this;
}

FieldView &FieldView::operator = (FieldView &&other)
{
    if(this != &other) {
        //dfield = other.field;
        cellView = other.cellView;
        state = other.state;
    }
    return *this;
}

FieldView::~FieldView()
{}

void FieldView::drowField(Field &field, QTableWidget *table, QGraphicsScene * sc)
{
    //std::cout<<"start redrow"<<std::endl;
    //std::cout<<table->rowCount()<<std::endl;
    //this->field = field;
    int n = field.getHeight();
    int m = field.getWidth();
    //std::cout<<"cras"<<std::endl;
    if(n > 0 && m > 0) {
        //table->setColumnCount(m);
        //table->setRowCount(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //std::cout<<"redrow"<<i<<" "<< j  <<std::endl;
                cellView.drowCell(table->item(i,j), field.cells[i][j], field.positionPlayer);
                //table->setItem(i,j,cellView.drowNewCell(field.cells[i][j], field.positionPlayer));
            }
        }
    }
    drowScene(field, sc);
}

void FieldView::drowScene(Field &field, QGraphicsScene *sc)
{
    sc->clear();
    double h_sector = sc->height()/field.height;
    double w_sector = sc->width()/field.width;
    QPen pen(QColor(0, 255, 155));
    for(int i = 0; i < field.height; i++) {
        sc->addLine(0, h_sector * i, sc->width(), h_sector * i, pen);
    }
    sc->addLine(0, sc->height(), sc->width(), sc->height(), pen);
    for(int j = 0; j < field.width; j++) {
        sc->addLine(w_sector * j, 0, w_sector * j, sc->height(), pen);
    }
    sc->addLine(sc->width(), 0, sc->width(), sc->height() , pen);
    for(int i = 0; i < field.width; i++) {
        for(int j = 0; j < field.height; j++) {
        }
    }
}

void FieldView::toString(const Field &field)
{
    state.clear();
    state = "FS:\n";
    state += std::to_string(field.height) + " " + std::to_string(field.width) + "\n";
    for(int i = 0; i < field.height; i++) {
        for(int j = 0; j < field.width; j++) {
            state += cellView.toString(field.cells[i][j]);
            state +=" ";
        }
        state +="\n";
    }
    state += ":FE\n";
}




