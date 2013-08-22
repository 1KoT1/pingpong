#include "gamescene.h"

const double racketWidth = 100, racketHeight = 10;

GameScene::GameScene(double width, double height):
	m_width(width),
	m_height(height),
	m_ball(new Ball(10, width / 2, height / 2)),
	m_topRacket(new Racket(racketWidth, racketHeight, width / 2 - racketWidth / 2, 0)),
	m_bottomRacket(new Racket(racketWidth, racketHeight, width / 2 - racketWidth / 2, height - racketHeight))
{
}

double GameScene::width() const
{
	return m_width;
}

double GameScene::height() const
{
	return m_height;
}

Ball *GameScene::ball() const
{
	return m_ball.get();
}

Racket *GameScene::topRacket() const
{
	return m_topRacket.get();
}

Racket *GameScene::bottomRacket() const
{
	return m_bottomRacket.get();
}
