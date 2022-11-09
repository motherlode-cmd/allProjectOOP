/****************************************************************************
** Meta object code from reading C++ file 'commandreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Mediator/commandreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommandReader_t {
    QByteArrayData data[15];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandReader_t qt_meta_stringdata_CommandReader = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CommandReader"
QT_MOC_LITERAL(1, 14, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "keyPressEvent"
QT_MOC_LITERAL(4, 51, 10), // "QKeyEvent*"
QT_MOC_LITERAL(5, 62, 1), // "e"
QT_MOC_LITERAL(6, 64, 13), // "on_up_clicked"
QT_MOC_LITERAL(7, 78, 15), // "on_down_clicked"
QT_MOC_LITERAL(8, 94, 15), // "on_left_clicked"
QT_MOC_LITERAL(9, 110, 16), // "on_right_clicked"
QT_MOC_LITERAL(10, 127, 28), // "on_pushButton_logger_clicked"
QT_MOC_LITERAL(11, 156, 29), // "on_checkBox_info_stateChanged"
QT_MOC_LITERAL(12, 186, 4), // "arg1"
QT_MOC_LITERAL(13, 191, 30), // "on_checkBox_state_stateChanged"
QT_MOC_LITERAL(14, 222, 30) // "on_checkBox_Error_stateChanged"

    },
    "CommandReader\0on_pushButton_clicked\0"
    "\0keyPressEvent\0QKeyEvent*\0e\0on_up_clicked\0"
    "on_down_clicked\0on_left_clicked\0"
    "on_right_clicked\0on_pushButton_logger_clicked\0"
    "on_checkBox_info_stateChanged\0arg1\0"
    "on_checkBox_state_stateChanged\0"
    "on_checkBox_Error_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    1,   65,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    1,   73,    2, 0x0a /* Public */,
      13,    1,   76,    2, 0x0a /* Public */,
      14,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void CommandReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandReader *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->on_up_clicked(); break;
        case 3: _t->on_down_clicked(); break;
        case 4: _t->on_left_clicked(); break;
        case 5: _t->on_right_clicked(); break;
        case 6: _t->on_pushButton_logger_clicked(); break;
        case 7: _t->on_checkBox_info_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_checkBox_state_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_checkBox_Error_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommandReader::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CommandReader.data,
    qt_meta_data_CommandReader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommandReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommandReader.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CommandReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
