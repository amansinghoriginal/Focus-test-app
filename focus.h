#ifndef FOCUS_H
#define FOCUS_H

#include <QObject>
#include <QVariant>
#include "dbusconnection.h"
class Focus : public QObject
{
	Q_OBJECT

public:
	Focus(QObject *parent=0);

public Q_SLOTS:
	void slotStateChanged();

private:
	DBusConnection c;
};

#endif //FOCUS
