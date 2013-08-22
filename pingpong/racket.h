#ifndef RACKET_H
#define RACKET_H

#include <QObject>

class Racket : QObject
{
	Q_OBJECT
public:
	Racket(double width, double height, double x, double y, QObject *parent);

	/** Ширина ракетки.*/
	double width() const;
	/** Высота ракетки.*/
	double height() const;

	/** Горизонтальная координата ракетки.*/
	double x() const;
	/** Установить горизонтальную координату ракетки.*/
	void setX(double x);

	/** Вертикальная координата шарика.*/
	double y() const;
	/** Установить вертикальную координату шарика.*/
	void setY(double y);
private:
	/** Ширина ракетки.*/
	double m_width;
	/** Высота ракетки.*/
	double m_height;

	/** Горизонтальная координата ракетки.*/
	double m_x;
	/** Вертикальная координата шарика.*/
	double m_y;
};

#endif // RACKET_H
