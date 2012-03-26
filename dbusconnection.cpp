#include "dbusconnection.h"

DBusConnection::DBusConnection()
{
	dbusConnection = connectDBus();
}

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

	return QDBusConnection::connectToBus(busAddress,"a11y");
}
