#include <QtGui>
#include "mainwindow.h"
#include "../pingpong/gamescene.h"
#include "../pingpong/gamecontroller.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	GameScene gS(500, 500);
	GameController gC(&gS);
	MainWindow window(&gS, &gC);
	window.setWindowTitle("QT OpenGL - Lesson 1");
	window.setGeometry(100,100,500,500);
	window.show();
	window.setMouseTracking(true); // вызывать метод mouseMoveEvent при изменении позиции указателя, даже без клика кнопкой мыши

	return app.exec();
}
