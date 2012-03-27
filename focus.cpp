#include "focus.h"
#include "dbusconnection.h"
#include <stdio.h>
#include <QDBusMessage>

Focus::Focus(QObject *parent)
	:QObject(parent)
{
	if(!c.connection().registerService("org.aman.focus"))
		printf("Could not register service\n");

	if(!c.connection().connect("","",
		"org.a11y.atspi.Event.Object",
		"StateChanged",
		this,
		SLOT(slotStateChanged(const QString&,int))))
			printf("Could not connect the slot to signal\n");

	QVariantList arguments;
	arguments << QString("object:state-changed") << QString("focus:");

	QDBusMessage m = QDBusMessage::createMethodCall("org.a11y.atspi.Registry",
				"/org/a11y/atspi/registry",
				"org.a11y.atspi.Registry",
				"RegisterEvent");

	m.setArguments(arguments);

	QDBusMessage reply = c.connection().call(m);
}

void Focus::slotStateChanged(const QString &name,int detail1)
{
	static int x=0;
	if(name == "focused" && detail1==1){
		printf("%d. Focus Changed\n",x++);
	}
}
