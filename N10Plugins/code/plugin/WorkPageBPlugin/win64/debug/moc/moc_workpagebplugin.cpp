/****************************************************************************
** Meta object code from reading C++ file 'workpagebplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../workpagebplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workpagebplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkPageBPlugin_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkPageBPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkPageBPlugin_t qt_meta_stringdata_WorkPageBPlugin = {
    {
QT_MOC_LITERAL(0, 0, 15) // "WorkPageBPlugin"

    },
    "WorkPageBPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkPageBPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void WorkPageBPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject WorkPageBPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WorkPageBPlugin.data,
    qt_meta_data_WorkPageBPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WorkPageBPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkPageBPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkPageBPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ComPluginInterface"))
        return static_cast< ComPluginInterface*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.ComPluginInterface/1.0"))
        return static_cast< ComPluginInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int WorkPageBPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x28,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'C',  'o',  'm', 
    'P',  'l',  'u',  'g',  'i',  'n',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e',  '/', 
    '1',  '.',  '0', 
    // "className"
    0x03,  0x6f,  'W',  'o',  'r',  'k',  'P',  'a', 
    'g',  'e',  'B',  'P',  'l',  'u',  'g',  'i', 
    'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(WorkPageBPlugin, WorkPageBPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
