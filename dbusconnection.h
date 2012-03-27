#ifndef DBUSCONNECTION_H
#define DBUSCONNECTION_H

#include <QDBusConnection>
#include <QString>

class DBusConnection
{
public:
	DBusConnection();
	QDBusConnection connection() const;

private:
	QString getAccessibilityBusAddress() const;
	QDBusConnection connectDBus() const;

	QDBusConnection dbusConnection;
};

#endif //DBUSCONNECTION_H
