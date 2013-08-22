#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QSize>

class Ball;
class Racket;

class GameScene : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QObject* ball READ ballProperty NOTIFY ballChanged)
	Q_PROPERTY(QObject* topRacket READ topRacketProperty NOTIFY topRacketChanged)
	Q_PROPERTY(QObject* bottomRacket READ bottomRacketProperty NOTIFY bottomRacketChanged)
	Q_PROPERTY(QSizeF size READ size WRITE setSize NOTIFY sizeChanged)
public:
	GameScene(double width, double height, QObject *parent = 0);

	/** Ширина сцены.*/
	double width() const;
	/** Высота сцены.*/
	double height() const;
	/** Размер сцены.*/
	QSizeF size() const;
	void setSize(const QSizeF &size);

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
	void sizeChanged();

private:
	/** Размер сцены.*/
	QSizeF m_size;

	Ball *m_ball;
	Racket *m_topRacket;
	Racket *m_bottomRacket;
};

#endif // GAMESCENE_H
