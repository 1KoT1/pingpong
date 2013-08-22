#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>

class Ball;
class Racket;

class GameScene : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QObject* ball READ ballProperty NOTIFY ballChanged)
	Q_PROPERTY(QObject* topRacket READ topRacketProperty NOTIFY topRacketChanged)
	Q_PROPERTY(QObject* bottomRacket READ bottomRacketProperty NOTIFY bottomRacketChanged)
public:
	GameScene(double width, double height, QObject *parent = 0);

	/** Ширина ракетки.*/
	double width() const;
	/** Высота ракетки.*/
	double height() const;

	Ball *ball() const;
	Racket *topRacket() const;
	Racket *bottomRacket() const;
	QObject *ballProperty() const;
	QObject *topRacketProperty() const;
	QObject *bottomRacketProperty() const;

signals:
	void ballChanged();
	void topRacketChanged();
	void bottomRacketChanged();

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
