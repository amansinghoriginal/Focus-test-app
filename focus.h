#ifndef FOCUS_H
#define FOCUS_H

#include <QObject>
#include <QVariant>
#include <QtDBus>
#include "dbusconnection.h"

class Focus : public QObject
{
	Q_OBJECT

public:
	Focus(QObject *parent=0);

public Q_SLOTS:
	void slotStateChanged(const QString&,int);

private:
	DBusConnection c;
};

#endif //FOCUS
