#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "gamecontroller.h"
#include "gamescene.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
		GameScene gS(360, 360);
		GameController gC(&gS);
		viewer.rootContext()->setContextProperty("gameScene", &gS);
		viewer.rootContext()->setContextProperty("gameController", &gC);
    viewer.setMainQmlFile(QStringLiteral("qml/pingpong/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
