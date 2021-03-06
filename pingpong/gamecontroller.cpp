#include "gamecontroller.h"
#include "gamescene.h"
#include "racket.h"
#include "ball.h"
#include <QTimer>
#include <QPoint>
#include <cmath>

const double racketSpeed = 10;

GameController::GameController(GameScene *gameScene, QObject *parent):
	QObject(parent),
	m_gameScene(gameScene)
{
	auto timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
	timer->start(50);
}

void GameController::racketsGoToLeft()
{
	moveRackets(-racketSpeed);
}

void GameController::racketsGoToRight()
{
	moveRackets(racketSpeed);
}

void GameController::setRacketsPosition(qreal position)
{
	if(position >= 0 && position <= m_gameScene->width() - m_gameScene->bottomRacket()->width())
	{
		m_gameScene->bottomRacket()->setX(position);
		m_gameScene->topRacket()->setX(position);
	}
}

void GameController::setSceneSize(qreal width, qreal height)
{
	m_gameScene->setSize(QSizeF(width, height));
	m_gameScene->bottomRacket()->setY(height - m_gameScene->bottomRacket()->height());
	if(m_gameScene->ball()->x() > width)
		m_gameScene->ball()->setX(width);
}

qreal delta(qreal A, qreal B, qreal C, QPointF O)
{
	return fabs(A * O.x() + B * O.y() + C) / sqrt(A * A + B * B);
}

void GameController::checkBallSpeed()
{
	if((delta(0, -1, m_gameScene->topRacket()->bottom(), m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()
			&& m_gameScene->ball()->x() >= m_gameScene->topRacket()->x()
			&& m_gameScene->ball()->x() < m_gameScene->topRacket()->right())
		 ||
		 (delta(0, -1, m_gameScene->bottomRacket()->y(), m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()
			&& m_gameScene->ball()->x() >= m_gameScene->bottomRacket()->x()
			&& m_gameScene->ball()->x() < m_gameScene->bottomRacket()->right()))
	{
		m_gameScene->ball()->setSpeedY(-m_gameScene->ball()->speedY());
	}

	if((delta(-1, 0, m_gameScene->topRacket()->x(), m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()
			&& m_gameScene->ball()->y() >= m_gameScene->topRacket()->y()
			&& m_gameScene->ball()->y() < m_gameScene->topRacket()->bottom())
		 ||
		 (delta(-1, 0, m_gameScene->topRacket()->right(), m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()
			&& m_gameScene->ball()->y() >= m_gameScene->topRacket()->y()
			&& m_gameScene->ball()->y() < m_gameScene->topRacket()->bottom())
		 ||
		 (delta(-1, 0, m_gameScene->bottomRacket()->x(), m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()
			&& m_gameScene->ball()->y() >= m_gameScene->bottomRacket()->y()
			&& m_gameScene->ball()->y() < m_gameScene->bottomRacket()->bottom())
		 ||
		 (delta(-1, 0, m_gameScene->bottomRacket()->right(), m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()
			&& m_gameScene->ball()->y() >= m_gameScene->bottomRacket()->y()
			&& m_gameScene->ball()->y() < m_gameScene->bottomRacket()->bottom())
		 ||
		 (delta(-1, 0, 0, m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()
			|| delta(-1, 0, m_gameScene->width(), m_gameScene->ball()->coordinates()) < m_gameScene->ball()->radius()))
	{
		m_gameScene->ball()->setSpeedX(-m_gameScene->ball()->speedX());
	}
}

void GameController::tick()
{
	checkBallSpeed();

	auto newCoord = m_gameScene->ball()->coordinates() + m_gameScene->ball()->speed();
	if(newCoord.y() > m_gameScene->height())
		newCoord.setY(0);
	if(newCoord.y() < 0)
		newCoord.setY(m_gameScene->height());

	m_gameScene->ball()->setCoordinates(newCoord);
}

void GameController::moveRackets(double step)
{
	setRacketsPosition(m_gameScene->bottomRacket()->x() + step);
}
