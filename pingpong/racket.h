#ifndef RACKET_H
#define RACKET_H

#include <QObject>

class Racket : public QObject
{
	Q_OBJECT
	Q_PROPERTY(double x READ x NOTIFY xChanged)
	Q_PROPERTY(double y READ y NOTIFY yChanged)
	Q_PROPERTY(double width READ width NOTIFY widthChanged)
	Q_PROPERTY(double height READ height NOTIFY heightChanged)
public:
	Racket(double width, double height, double x, double y, QObject *parent = 0);

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

signals:
	void xChanged();
	void yChanged();
	void widthChanged();
	void heightChanged();
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
