/****************************************************************************
** Meta object code from reading C++ file 'youlose.h'
**
** Created: Mon 24. Dec 00:27:01 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorldOfClots/youlose.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'youlose.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_YouLose[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      18,    8,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_YouLose[] = {
    "YouLose\0\0toMenu()\0tryAgain(int)\0"
};

void YouLose::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        YouLose *_t = static_cast<YouLose *>(_o);
        switch (_id) {
        case 0: _t->toMenu(); break;
        case 1: _t->tryAgain((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData YouLose::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject YouLose::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_YouLose,
      qt_meta_data_YouLose, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &YouLose::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *YouLose::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *YouLose::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YouLose))
        return static_cast<void*>(const_cast< YouLose*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int YouLose::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void YouLose::toMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void YouLose::tryAgain(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
