/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu May 6 20:14:49 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      28,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     160,   11,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0slot_file_new()\0"
    "slot_file_open()\0slot_file_save()\0"
    "slot_file_exit()\0slot_difficulty_novice()\0"
    "slot_difficulty_intermediate()\0"
    "slot_difficulty_expert()\0slot_help_solve()\0"
    "slot_help_about()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slot_file_new(); break;
        case 1: slot_file_open(); break;
        case 2: slot_file_save(); break;
        case 3: slot_file_exit(); break;
        case 4: slot_difficulty_novice(); break;
        case 5: slot_difficulty_intermediate(); break;
        case 6: slot_difficulty_expert(); break;
        case 7: slot_help_solve(); break;
        case 8: slot_help_about(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
