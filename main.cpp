#include "QtSort.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMainWindow window;
	ChartWidget *widget = new ChartWidget(nullptr);
	window.setCentralWidget(widget);
	window.resize(1500, 1000);
	window.show();

	return a.exec();
}
