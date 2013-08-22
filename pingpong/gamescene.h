#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <memory>
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

	Ball *ball() const;
	Racket *topRacket() const;
	Racket *bottomRacket() const;

private:
	/** Ширина поля.*/
	double m_width;
	/** Высота поля.*/
	double m_height;

	std::unique_ptr<Ball> m_ball;
	std::unique_ptr<Racket> m_topRacket;
	std::unique_ptr<Racket> m_bottomRacket;
};

#endif // GAMESCENE_H
