#include <QCoreApplication>
#include "focus.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc,argv);
	Focus *focus = new Focus;
	return app.exec();
}
