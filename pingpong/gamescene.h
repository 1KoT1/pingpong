#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>

class Ball;
class Racket;

class GameScene : QObject
{
	Q_OBJECT
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

	Ball *m_ball;
	Racket *m_topRacket;
	Racket *m_bottomRacket;
};

#endif // GAMESCENE_H
