#include "focus.h"
#include "dbusconnection.h"
#include <stdio.h>
#include <QDBusMessage>
Focus::Focus(QObject *parent)
	:QObject(parent)
{
	c.connection().registerService("org.aman.focus");

	c.connection().connect(QString(),QString(),
		"org.a11y.atspi.Event.Object",
		"StateChanged",
		this,
		SLOT(slotStateChanged));

	QVariantList arguments;
	arguments << QString("object:state-changed") << QString("focus:");

	QDBusMessage m = QDBusMessage::createMethodCall("org.a11y.atspi.Registry",
	"/org/a11y/atspi/registry",
	"org.a11y.atspi.Registry",
	"RegisterEvent");

	m.setArgumentList(arguments);

	c.connection().call(m);
}

void Focus::slotStateChanged()
{
	printf("Signal Recieved\n");
}
