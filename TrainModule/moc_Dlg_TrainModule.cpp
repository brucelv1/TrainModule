/****************************************************************************
** Meta object code from reading C++ file 'Dlg_TrainModule.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Dlg_TrainModule.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Dlg_TrainModule.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dlg_TrainModule[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      45,   16,   16,   16, 0x0a,
      72,   16,   16,   16, 0x0a,
      99,   16,   16,   16, 0x0a,
     121,   16,   16,   16, 0x0a,
     145,   16,   16,   16, 0x0a,
     168,   16,   16,   16, 0x0a,
     199,   16,   16,   16, 0x0a,
     222,   16,   16,   16, 0x0a,
     239,   16,   16,   16, 0x0a,
     264,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dlg_TrainModule[] = {
    "Dlg_TrainModule\0\0on_Btn_Add_Finger_clicked()\0"
    "on_Btn_Add_Wrist_clicked()\0"
    "on_Btn_Add_Elbow_clicked()\0"
    "on_Btn_Save_clicked()\0on_Btn_Import_clicked()\0"
    "on_Btn_Start_clicked()\0"
    "on_Btn_Delete_Latest_clicked()\0"
    "on_Btn_Clear_clicked()\0qTimer_timeout()\0"
    "on_Btn_Armband_clicked()\0"
    "on_Btn_DataSave_clicked()\0"
};

void Dlg_TrainModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dlg_TrainModule *_t = static_cast<Dlg_TrainModule *>(_o);
        switch (_id) {
        case 0: _t->on_Btn_Add_Finger_clicked(); break;
        case 1: _t->on_Btn_Add_Wrist_clicked(); break;
        case 2: _t->on_Btn_Add_Elbow_clicked(); break;
        case 3: _t->on_Btn_Save_clicked(); break;
        case 4: _t->on_Btn_Import_clicked(); break;
        case 5: _t->on_Btn_Start_clicked(); break;
        case 6: _t->on_Btn_Delete_Latest_clicked(); break;
        case 7: _t->on_Btn_Clear_clicked(); break;
        case 8: _t->qTimer_timeout(); break;
        case 9: _t->on_Btn_Armband_clicked(); break;
        case 10: _t->on_Btn_DataSave_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Dlg_TrainModule::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dlg_TrainModule::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dlg_TrainModule,
      qt_meta_data_Dlg_TrainModule, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dlg_TrainModule::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dlg_TrainModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dlg_TrainModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dlg_TrainModule))
        return static_cast<void*>(const_cast< Dlg_TrainModule*>(this));
    if (!strcmp(_clname, "Ui_TrainModule"))
        return static_cast< Ui_TrainModule*>(const_cast< Dlg_TrainModule*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dlg_TrainModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
