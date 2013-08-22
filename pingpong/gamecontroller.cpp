#include "gamecontroller.h"
#include "gamescene.h"
#include "racket.h"

const double racketSpeed = 10;

GameController::GameController(GameScene *gameScene, QObject *parent):
	m_gameScene(gameScene),
	QObject(parent)
{
}

void GameController::racketsGoToLeft()
{
	moveRackets(-racketSpeed);
}

void GameController::racketsGoToRight()
{
	moveRackets(racketSpeed);
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
