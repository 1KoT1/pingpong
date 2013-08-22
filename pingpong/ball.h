#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QPoint>

class Ball : public QObject
{
	Q_OBJECT
	Q_PROPERTY(qreal x READ x NOTIFY coordChanged)
	Q_PROPERTY(qreal y READ y NOTIFY coordChanged)
	Q_PROPERTY(qreal radius READ radius NOTIFY radiusChanged)
public:
	Ball( qreal radius, ///< Радиус шарика.
				qreal x,      ///< Горизонтальная координата шарика.
				qreal y,      ///< Вертикальная координата шарика.
				qreal speedX, ///< Горизонтальная составляющая скорости.
				qreal speedY,  ///< Вертикальная составляющая скорости.
				QObject *parent = 0);

	Ball( qreal radius, ///< Радиус шарика.
				qreal x,      ///< Горизонтальная координата шарика.
				qreal y,       ///< Вертикальная координата шарика.
				QObject *parent = 0);

	/** Радиус шарика.*/
	qreal radius() const;

	/** Горизонтальная координата шарика.*/
	qreal x() const;
	/** Установить горизонтальную координату шарика.*/
	void setX(qreal x);

	/** Вертикальная координата шарика.*/
	qreal y() const;
	/** Установить вертикальную координату шарика.*/
	void setY(qreal y);

	/** Установить координаты шарика.*/
	void setCoordinates(QPointF coordinates);
	/** Координаты шарика.*/
	const QPointF &coordinates() const;

	/** Горизонтальная составляющая скорости.*/
	qreal speedX() const;
	/** Установить горизонтальную составляющую скорости.*/
	void setSpeedX(qreal speedX);

	/** Вертикальная составляющая скорости.*/
	qreal speedY() const;
	/** Установить вертикальную составляющую скорости.*/
	void setSpeedY(qreal speedY);

	/** Скорость.*/
	const QPointF &speed() const;
signals:
	void coordChanged();
	void radiusChanged();
private:
	/** Радиус шарика.*/
	qreal m_radius;

	/** Координаты шарика.*/
	QPointF m_coord;

	/** Горизонтальная составляющая скорости.*/
	QPointF m_speed;

};

#endif // BALL_H
