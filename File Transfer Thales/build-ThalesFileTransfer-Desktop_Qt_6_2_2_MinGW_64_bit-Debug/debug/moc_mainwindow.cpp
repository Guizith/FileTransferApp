/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ThalesFileTransfer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 21), // "on_run_button_clicked"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 8), // "stopfunc"
QT_MOC_LITERAL(43, 22), // "on_run_button2_clicked"
QT_MOC_LITERAL(66, 7), // "checked"
QT_MOC_LITERAL(74, 6), // "putlog"
QT_MOC_LITERAL(81, 6), // "char[]"
QT_MOC_LITERAL(88, 4), // "srcc"
QT_MOC_LITERAL(93, 4), // "dstt"
QT_MOC_LITERAL(98, 11), // "putstartlog"
QT_MOC_LITERAL(110, 23), // "on_chart_button_clicked"
QT_MOC_LITERAL(134, 26), // "on_Save_Button_2_triggered"
QT_MOC_LITERAL(161, 24), // "on_Load_Config_triggered"
QT_MOC_LITERAL(186, 33), // "on_Log_Report_Directory_trigg..."
QT_MOC_LITERAL(220, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(242, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(266, 23) // "on_actionQuit_triggered"

    },
    "MainWindow\0on_run_button_clicked\0\0"
    "stopfunc\0on_run_button2_clicked\0checked\0"
    "putlog\0char[]\0srcc\0dstt\0putstartlog\0"
    "on_chart_button_clicked\0"
    "on_Save_Button_2_triggered\0"
    "on_Load_Config_triggered\0"
    "on_Log_Report_Directory_triggered\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_actionQuit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    1,   88,    2, 0x08,    3 /* Private */,
       6,    2,   91,    2, 0x08,    5 /* Private */,
      10,    0,   96,    2, 0x08,    8 /* Private */,
      11,    0,   97,    2, 0x08,    9 /* Private */,
      12,    0,   98,    2, 0x08,   10 /* Private */,
      13,    0,   99,    2, 0x08,   11 /* Private */,
      14,    0,  100,    2, 0x08,   12 /* Private */,
      15,    0,  101,    2, 0x08,   13 /* Private */,
      16,    0,  102,    2, 0x08,   14 /* Private */,
      17,    0,  103,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_run_button_clicked(); break;
        case 1: _t->stopfunc(); break;
        case 2: _t->on_run_button2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->putlog((*reinterpret_cast< char(*)[]>(_a[1])),(*reinterpret_cast< char(*)[]>(_a[2]))); break;
        case 4: _t->putstartlog(); break;
        case 5: _t->on_chart_button_clicked(); break;
        case 6: _t->on_Save_Button_2_triggered(); break;
        case 7: _t->on_Load_Config_triggered(); break;
        case 8: _t->on_Log_Report_Directory_triggered(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->on_actionQuit_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char, std::false_type>, QtPrivate::TypeAndForceComplete<char, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
