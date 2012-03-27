#include "dbusconnection.h"
#include <stdio.h>
#include <QtDBus>
DBusConnection::DBusConnection()
	:dbusConnection(connectDBus())
{}

QString DBusConnection::getAccessibilityBusAddress() const
{
	QDBusMessage m = QDBusMessage::createMethodCall("org.a11y.Bus",
	"/org/a11y/bus",
	"org.a11y.Bus",
	"GetAddress");

	QDBusMessage reply = QDBusConnection::sessionBus().call(m);

	return reply.arguments().at(0).toString();
}

QDBusConnection DBusConnection::connectDBus() const
{
	QString busAddress = getAccessibilityBusAddress();
	if(busAddress.isEmpty())
		printf("Hallelujah");
	else printf("%s\n",qPrintable(busAddress));

	return QDBusConnection::connectToBus(busAddress,"a11y");
}

QDBusConnection DBusConnection::connection() const
{
	return dbusConnection;
}
