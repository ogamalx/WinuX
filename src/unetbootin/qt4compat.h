#ifndef QT4COMPAT_H
#define QT4COMPAT_H

#include <QtCore>
#include <QtNetwork>

// Qt4 compatibility shims for Qt5 build
// Note: These are stub implementations for compile-time validation only
// Runtime functionality is not guaranteed

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)

// Forward declarations
class QUrlInfo;
class QHttpRequestHeader;
class QHttpResponseHeader;

// Stub QHttpRequestHeader class for Qt5 compatibility
class QHttpRequestHeader {
public:
    QHttpRequestHeader() {}
    QHttpRequestHeader(const QString &, const QString &) {}
    void setRequest(const QString &, const QString &) {}
    void setValue(const QString &, const QString &) {}
};

// Stub QHttpResponseHeader class for Qt5 compatibility
class QHttpResponseHeader {
public:
    QHttpResponseHeader() {}
    QHttpResponseHeader(const QString &) {}
    int statusCode() const { return 200; }
    bool hasKey(const QString &) const { return false; }
    QString value(const QString &) const { return QString(); }
};

// Stub QUrlInfo class for Qt5 compatibility
class QUrlInfo {
public:
    QUrlInfo() {}
    QString name() const { return QString(); }
    qint64 size() const { return 0; }
    bool isFile() const { return true; }
    bool isDir() const { return false; }
    bool isValid() const { return true; }
    bool isReadable() const { return true; }
    bool isSymLink() const { return false; }
};

// Stub QHttp class for Qt5 compatibility
class QHttp : public QObject {
    Q_OBJECT
public:
    QHttp(QObject *parent = nullptr) : QObject(parent) {}
    void setHost(const QString &) {}
    int request(const QHttpRequestHeader &, QIODevice * = nullptr, QIODevice * = nullptr) { return 0; }
    int request(const QString &) { return 0; }
    QString lastResponse() const { return QString(); }
    QByteArray readAll() { return QByteArray(); }
    void close() {}
signals:
    void done(bool);
    void dataReadProgress(int, int);
};

// Stub QFtp class for Qt5 compatibility
class QFtp : public QObject {
    Q_OBJECT
public:
    enum TransferType { Binary, Ascii };
    QFtp(QObject *parent = nullptr) : QObject(parent) {}
    void connectToHost(const QString &, quint16 = 21) {}
    void login(const QString & = QString(), const QString & = QString()) {}
    int get(const QString &, QIODevice * = nullptr, TransferType = Binary) { return 0; }
    int list(const QString & = QString()) { return 0; }
    void close() {}
signals:
    void done(bool);
    void dataTransferProgress(qint64, qint64);
    void listInfo(const QUrlInfo &);
};

#endif // QT_VERSION >= 5.0.0

#endif // QT4COMPAT_H
