/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created: Mon 24. Dec 00:26:57 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorldOfClots/menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Menu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      14,    5,    5,    5, 0x05,
      21,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,    5,    5,    5, 0x0a,
      57,   50,    5,    5, 0x0a,
      72,   50,    5,    5, 0x0a,
      88,   50,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Menu[] = {
    "Menu\0\0start()\0stop()\0sizeForGame()\0"
    "returnToMenu()\0number\0outputWin(int)\0"
    "outputLose(int)\0restartLevel(int)\0"
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Menu *_t = static_cast<Menu *>(_o);
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->stop(); break;
        case 2: _t->sizeForGame(); break;
        case 3: _t->returnToMenu(); break;
        case 4: _t->outputWin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->outputLose((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->restartLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Menu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Menu::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_Menu,
      qt_meta_data_Menu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Menu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Menu))
        return static_cast<void*>(const_cast< Menu*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Menu::start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Menu::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Menu::sizeForGame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
