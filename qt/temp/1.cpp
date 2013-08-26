#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QLabel * w = new QLabel("hello");
	w->resize(200, 100);

	w->show();

	return a.exec();
}

