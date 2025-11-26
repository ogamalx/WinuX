/****************************************************************************
** Meta object code from reading C++ file 'ganalytics.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ganalytics.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ganalytics.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GAnalytics_t {
    QByteArrayData data[36];
    char stringdata0[436];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GAnalytics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GAnalytics_t qt_meta_stringdata_GAnalytics = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GAnalytics"
QT_MOC_LITERAL(1, 11, 12), // "sendPageview"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "docHostname"
QT_MOC_LITERAL(4, 37, 4), // "page"
QT_MOC_LITERAL(5, 42, 5), // "title"
QT_MOC_LITERAL(6, 48, 9), // "sendEvent"
QT_MOC_LITERAL(7, 58, 13), // "eventCategory"
QT_MOC_LITERAL(8, 72, 11), // "eventAction"
QT_MOC_LITERAL(9, 84, 10), // "eventLabel"
QT_MOC_LITERAL(10, 95, 10), // "eventValue"
QT_MOC_LITERAL(11, 106, 10), // "withParams"
QT_MOC_LITERAL(12, 117, 15), // "sendTransaction"
QT_MOC_LITERAL(13, 133, 13), // "transactionID"
QT_MOC_LITERAL(14, 147, 22), // "transactionAffiliation"
QT_MOC_LITERAL(15, 170, 8), // "sendItem"
QT_MOC_LITERAL(16, 179, 8), // "itemName"
QT_MOC_LITERAL(17, 188, 10), // "sendSocial"
QT_MOC_LITERAL(18, 199, 13), // "socialNetwork"
QT_MOC_LITERAL(19, 213, 12), // "socialAction"
QT_MOC_LITERAL(20, 226, 18), // "socialActionTarget"
QT_MOC_LITERAL(21, 245, 13), // "sendException"
QT_MOC_LITERAL(22, 259, 20), // "exceptionDescription"
QT_MOC_LITERAL(23, 280, 14), // "exceptionFatal"
QT_MOC_LITERAL(24, 295, 10), // "sendTiming"
QT_MOC_LITERAL(25, 306, 11), // "sendAppview"
QT_MOC_LITERAL(26, 318, 7), // "appName"
QT_MOC_LITERAL(27, 326, 10), // "appVersion"
QT_MOC_LITERAL(28, 337, 10), // "screenName"
QT_MOC_LITERAL(29, 348, 10), // "endSession"
QT_MOC_LITERAL(30, 359, 12), // "postFinished"
QT_MOC_LITERAL(31, 372, 14), // "QNetworkReply*"
QT_MOC_LITERAL(32, 387, 5), // "reply"
QT_MOC_LITERAL(33, 393, 9), // "postError"
QT_MOC_LITERAL(34, 403, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(35, 431, 4) // "code"

    },
    "GAnalytics\0sendPageview\0\0docHostname\0"
    "page\0title\0sendEvent\0eventCategory\0"
    "eventAction\0eventLabel\0eventValue\0"
    "withParams\0sendTransaction\0transactionID\0"
    "transactionAffiliation\0sendItem\0"
    "itemName\0sendSocial\0socialNetwork\0"
    "socialAction\0socialActionTarget\0"
    "sendException\0exceptionDescription\0"
    "exceptionFatal\0sendTiming\0sendAppview\0"
    "appName\0appVersion\0screenName\0endSession\0"
    "postFinished\0QNetworkReply*\0reply\0"
    "postError\0QNetworkReply::NetworkError\0"
    "code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GAnalytics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,  114,    2, 0x0a /* Public */,
       6,    5,  121,    2, 0x0a /* Public */,
       6,    4,  132,    2, 0x2a /* Public | MethodCloned */,
       6,    3,  141,    2, 0x2a /* Public | MethodCloned */,
       6,    2,  148,    2, 0x2a /* Public | MethodCloned */,
       6,    1,  153,    2, 0x2a /* Public | MethodCloned */,
       6,    0,  156,    2, 0x2a /* Public | MethodCloned */,
      12,    2,  157,    2, 0x0a /* Public */,
      12,    1,  162,    2, 0x2a /* Public | MethodCloned */,
      15,    1,  165,    2, 0x0a /* Public */,
      17,    3,  168,    2, 0x0a /* Public */,
      21,    2,  175,    2, 0x0a /* Public */,
      21,    1,  180,    2, 0x2a /* Public | MethodCloned */,
      24,    0,  183,    2, 0x0a /* Public */,
      25,    3,  184,    2, 0x0a /* Public */,
      25,    2,  191,    2, 0x2a /* Public | MethodCloned */,
      25,    1,  196,    2, 0x2a /* Public | MethodCloned */,
      29,    0,  199,    2, 0x0a /* Public */,
      30,    1,  200,    2, 0x08 /* Private */,
      33,    1,  203,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    7,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   22,   23,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   26,   27,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   26,   27,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 34,   35,

       0        // eod
};

void GAnalytics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GAnalytics *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendPageview((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->sendEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->sendEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->sendEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->sendEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->sendEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendEvent(); break;
        case 7: _t->sendTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->sendTransaction((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->sendItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->sendSocial((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->sendException((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->sendException((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->sendTiming(); break;
        case 14: _t->sendAppview((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 15: _t->sendAppview((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: _t->sendAppview((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->endSession(); break;
        case 18: _t->postFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 19: _t->postError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GAnalytics::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GAnalytics.data,
    qt_meta_data_GAnalytics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GAnalytics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GAnalytics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GAnalytics.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GAnalytics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
