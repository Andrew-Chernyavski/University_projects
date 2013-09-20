/****************************************************************************
** Meta object code from reading C++ file 'sceneblhole.h'
**
** Created: Mon 24. Dec 00:27:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorldOfClots/sceneblhole.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sceneblhole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SceneBlHole[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      20,   12,   12,   12, 0x05,
      32,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SceneBlHole[] = {
    "SceneBlHole\0\0stop()\0youWin(int)\0"
    "youLose(int)\0updating()\0"
};

void SceneBlHole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SceneBlHole *_t = static_cast<SceneBlHole *>(_o);
        switch (_id) {
        case 0: _t->stop(); break;
        case 1: _t->youWin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->youLose((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updating(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SceneBlHole::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SceneBlHole::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_SceneBlHole,
      qt_meta_data_SceneBlHole, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SceneBlHole::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SceneBlHole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SceneBlHole::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SceneBlHole))
        return static_cast<void*>(const_cast< SceneBlHole*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int SceneBlHole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SceneBlHole::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SceneBlHole::youWin(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SceneBlHole::youLose(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
