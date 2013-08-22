#include "gamecontroller.h"
#include "gamescene.h"

const double racketSpeed = 10;

GameController::GameController(GameScene *gameScene):
	m_gameScene(gameScene)
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
