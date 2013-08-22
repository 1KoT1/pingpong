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
	m_gameScene->bottomRacket()->setX(m_gameScene->bottomRacket()->x() + step);
	m_gameScene->topRacket()->setX(m_gameScene->bottomRacket()->x());
}
