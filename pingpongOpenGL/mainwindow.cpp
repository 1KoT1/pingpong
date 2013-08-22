#include "mainwindow.h"
#include "../pingpong/gamescene.h"
#include "../pingpong/gamecontroller.h"
#include "../pingpong/ball.h"
#include "../pingpong/racket.h"

MainWindow::MainWindow(GameScene *gameScene, GameController *gameController, QWidget* parent) :
	QGLWidget(parent),
	m_gameScene(gameScene),
	m_gameController(gameController)
{
	setFormat(QGLFormat(QGL::DoubleBuffer)); // Двойная буферизация
	glDepthFunc(GL_LEQUAL); // Буфер глубины
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	timer->start(10);
}

void MainWindow::initializeGL()
{
	qglClearColor(Qt::white);
}

void MainWindow::resizeGL(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLint)width, (GLint)height);
	m_gameController->setSceneSize(width, height);
}

void MainWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // чистим буфер изображения и буфер глубины
	glMatrixMode(GL_PROJECTION); // устанавливаем матрицу
	glLoadIdentity(); // загружаем матрицу
	glOrtho(0,m_gameScene->width(),m_gameScene->height(),0,1,0); // подготавливаем плоскости для матрицы
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	drowRacket(m_gameScene->topRacket());
	drowRacket(m_gameScene->bottomRacket());
	drowBall();

	swapBuffers();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	switch (e->key())
	{
		case Qt::Key_Left:
			m_gameController->racketsGoToLeft();
			return;
		case Qt::Key_Right:
			m_gameController->racketsGoToRight();
			return;
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
	m_gameController->setRacketsPosition(e->x());
}


void MainWindow::drowBall()
{
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	const qreal l = M_PI * 2;
	for (qreal i = 0; i < l; i += l / 10) {
		glVertex2f(m_gameScene->ball()->x() + cos(i) * m_gameScene->ball()->radius(),
							 m_gameScene->ball()->y() - sin(i) * m_gameScene->ball()->radius());
	}
	glEnd();
}

void MainWindow::drowRacket(const Racket *racket)
{
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(racket->x(), racket->y());
	glVertex2f(racket->right(), racket->y());
	glVertex2f(racket->right(), racket->bottom());
	glVertex2f(racket->x(), racket->bottom());
	glEnd();
}
