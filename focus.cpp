#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusMessage>
#include <stdio.h>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc,argv);

	QDBusMessage m = QDBusMessage::createMethodCall("org.a11y.Bus",
											"/org/a11y/bus",
											"org.a11y.Bus",
											"GetAddress");
	QDBusMessage reply = QDBusConnection::sessionBus().call(m);
	QString address = reply.arguments().at(0).toString();
	printf("Accessibility Bus found at : %s\n",qPrintable(address));

	QDBusConnection a11y = QDBusConnection::connectToBus(address,"a11y");


	return app.exec();
}
