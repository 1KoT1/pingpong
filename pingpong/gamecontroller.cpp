#include "gamecontroller.h"
#include "gamescene.h"
#include "racket.h"
#include "ball.h"
#include <QTimer>

const double racketSpeed = 10;

GameController::GameController(GameScene *gameScene, QObject *parent):
	m_gameScene(gameScene),
	QObject(parent)
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

void GameController::tick()
{
	auto newX = m_gameScene->ball()->x() + m_gameScene->ball()->speedX();
	auto newY = m_gameScene->ball()->y() + m_gameScene->ball()->speedY();
	if(newY > m_gameScene->height())
		newY = 0;
	if(newY < 0)
		newY = m_gameScene->height();

	if(newX <= 0)
	{
		newX = 0;
		m_gameScene->ball()->setSpeedX(-m_gameScene->ball()->speedX());
	}

	if(newX >= m_gameScene->width())
	{
		newX = m_gameScene->width();
		m_gameScene->ball()->setSpeedX(-m_gameScene->ball()->speedX());
	}

	if(newX >= m_gameScene->topRacket()->x()
		 && newX <= m_gameScene->topRacket()->x() + m_gameScene->topRacket()->width()
		 && newY >= m_gameScene->topRacket()->y()
		 && newY <= m_gameScene->topRacket()->y() + m_gameScene->topRacket()->height())
	{
		newY = m_gameScene->topRacket()->y() + m_gameScene->topRacket()->height();
		m_gameScene->ball()->setSpeedY(-m_gameScene->ball()->speedY());
	}

	if(newX >= m_gameScene->bottomRacket()->x()
		 && newX <= m_gameScene->bottomRacket()->x() + m_gameScene->bottomRacket()->width()
		 && newY >= m_gameScene->bottomRacket()->y()
		 && newY <= m_gameScene->bottomRacket()->y() + m_gameScene->bottomRacket()->height())
	{
		newY = m_gameScene->bottomRacket()->y();
		m_gameScene->ball()->setSpeedY(-m_gameScene->ball()->speedY());
	}

	m_gameScene->ball()->setX(newX);
	m_gameScene->ball()->setY(newY);
}

void GameController::moveRackets(double step)
{
	auto position = m_gameScene->bottomRacket()->x() + step;
	if(position >= 0 && position <= m_gameScene->width() - m_gameScene->bottomRacket()->width())
	{
		m_gameScene->bottomRacket()->setX(position);
		m_gameScene->topRacket()->setX(position);
	}
}
