/****************************************************************************
** Meta object code from reading C++ file 'wordbookdock.h'
**
** Created: Mon Nov 5 21:36:23 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wordbookdock.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wordbookdock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wordbookDock[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   13,   13,   13, 0x08,
      61,   57,   13,   13, 0x08,
      87,   81,   13,   13, 0x08,
     117,   13,   13,   13, 0x0a,
     141,   14,  136,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_wordbookDock[] = {
    "wordbookDock\0\0word\0translate(QString)\0"
    "showSearchResult()\0pos\0displayMenu(QPoint)\0"
    "index\0selectionChanged(QModelIndex)\0"
    "toggleVisibility()\0bool\0addRecord(QString)\0"
};

void wordbookDock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wordbookDock *_t = static_cast<wordbookDock *>(_o);
        switch (_id) {
        case 0: _t->translate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->showSearchResult(); break;
        case 2: _t->displayMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->selectionChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->toggleVisibility(); break;
        case 5: { bool _r = _t->addRecord((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wordbookDock::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wordbookDock::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_wordbookDock,
      qt_meta_data_wordbookDock, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wordbookDock::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wordbookDock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wordbookDock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wordbookDock))
        return static_cast<void*>(const_cast< wordbookDock*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int wordbookDock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void wordbookDock::translate(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
