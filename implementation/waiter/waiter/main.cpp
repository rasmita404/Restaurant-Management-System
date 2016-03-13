#include "waiter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	waiter w;
	w.show();
	return a.exec();
}
