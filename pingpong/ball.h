#ifndef BALL_H
#define BALL_H

#include <QObject>

class Ball : public QObject
{
	Q_OBJECT
	Q_PROPERTY(double x READ x NOTIFY xChanged)
	Q_PROPERTY(double y READ y NOTIFY yChanged)
public:
	Ball( double radius, ///< Радиус шарика.
				double x,      ///< Горизонтальная координата шарика.
				double y,      ///< Вертикальная координата шарика.
				double speedX, ///< Горизонтальная составляющая скорости.
				double speedY,  ///< Вертикальная составляющая скорости.
				QObject *parent = 0);

	Ball( double radius, ///< Радиус шарика.
				double x,      ///< Горизонтальная координата шарика.
				double y,       ///< Вертикальная координата шарика.
				QObject *parent = 0);

	/** Радиус шарика.*/
	double radius() const;

	/** Горизонтальная координата шарика.*/
	double x() const;
	/** Установить горизонтальную координату шарика.*/
	void setX(double x);

	/** Вертикальная координата шарика.*/
	double y() const;
	/** Установить вертикальную координату шарика.*/
	void setY(double y);

	/** Горизонтальная составляющая скорости.*/
	double speedX() const;
	/** Установить горизонтальную составляющую скорости.*/
	void setSpeedX(double speedX);

	/** Вертикальная составляющая скорости.*/
	double speedY() const;
	/** Установить вертикальную составляющую скорости.*/
	void setSpeedY(double speedY);

signals:
	void xChanged();
	void yChanged();
private:
	/** Радиус шарика.*/
	double m_radius;

	/** Горизонтальная координата шарика.*/
	double m_x;
	/** Вертикальная координата шарика.*/
	double m_y;

	/** Горизонтальная составляющая скорости.*/
	double m_speedX;
	/** Вертикальная составляющая скорости.*/
	double m_speedY;

};

#endif // BALL_H
