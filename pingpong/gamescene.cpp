#include "gamescene.h"
#include "ball.h"
#include "racket.h"
#include <QDebug>

const double racketWidth = 100, racketHeight = 10;

GameScene::GameScene(double width, double height, QObject *parent):
	QObject(parent),
	m_size(QSizeF(width, height)),
	m_ball(new Ball(10, width / 2, height / 2, rand() % 20 - 10, rand() % 20 - 10, this)),
	m_topRacket(new Racket(racketWidth, racketHeight, width / 2 - racketWidth / 2, 0, this)),
	m_bottomRacket(new Racket(racketWidth, racketHeight, width / 2 - racketWidth / 2, height - racketHeight, this))
{
}

double GameScene::width() const
{
	return m_size.width();
}

double GameScene::height() const
{
	return m_size.height();
}

QSizeF GameScene::size() const
{
	return m_size;
}

void GameScene::setSize(const QSizeF &size)
{
	if(m_size != size)
	{
		m_size = size;
		emit sizeChanged();
	}
}

Ball *GameScene::ball() const
{
	return m_ball;
}

QObject *GameScene::ballProperty() const
{
	return ball();
}

Racket *GameScene::topRacket() const
{
	return m_topRacket;
}

QObject *GameScene::topRacketProperty() const
{
	return topRacket();
}

Racket *GameScene::bottomRacket() const
{
	return m_bottomRacket;
}

QObject *GameScene::bottomRacketProperty() const
{
	return bottomRacket();
}
