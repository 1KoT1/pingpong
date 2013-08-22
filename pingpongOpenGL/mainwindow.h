#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>

class GameScene;
class GameController;
class Racket;

class MainWindow : public QGLWidget
{
	Q_OBJECT

public:
	MainWindow(GameScene *gameScene, GameController *gameController, QWidget *parent = 0);

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void keyPressEvent(QKeyEvent *e);
	void mouseMoveEvent(QMouseEvent *e);

private:
	GameScene *m_gameScene;
	GameController *m_gameController;

	void drowBall();
	void drowRacket(const Racket *racket);
};

#endif // MAINWINDOW_H
