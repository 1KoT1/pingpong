#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "ball.h"
#include "racket.h"

class GameScene
{
public:
	GameScene(double width, double height);

	/** Ширина ракетки.*/
	double width() const;
	/** Высота ракетки.*/
	double height() const;

	const Ball *ball() const;
	const Racket *topRacket() const;
	const Racket *bottomRacket() const;

private:
	/** Ширина поля.*/
	double m_width;
	/** Высота поля.*/
	double m_height;

	Ball m_ball;
	Racket m_topRacket;
	Racket m_bottomRacket;
};

#endif // GAMESCENE_H
