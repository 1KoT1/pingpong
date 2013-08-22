#ifndef RACKET_H
#define RACKET_H

#include <QObject>
#include <QRect>

class Racket : public QObject
{
	Q_OBJECT
	Q_PROPERTY(qreal x READ x NOTIFY coordChanged)
	Q_PROPERTY(qreal y READ y NOTIFY coordChanged)
	Q_PROPERTY(qreal width READ width NOTIFY widthChanged)
	Q_PROPERTY(qreal height READ height NOTIFY heightChanged)
public:
	Racket(qreal width, qreal height, qreal x, qreal y, QObject *parent = 0);

	/** Ширина ракетки.*/
	qreal width() const;
	/** Высота ракетки.*/
	qreal height() const;

	/** Горизонтальная координата ракетки.*/
	qreal x() const;
	/** Установить горизонтальную координату ракетки.*/
	void setX(qreal x);

	/** Вертикальная координата ракетки.*/
	qreal y() const;
	/** Установить вертикальную координату шарика.*/
	void setY(qreal y);

	/** Координаты шарика.*/
	QPointF coordinates() const;
	/** Установить координаты шарика.*/
	void setCoordinates(QPointF coordinates);

	/** Нижняя граница ракетки.*/
	qreal bottom() const;

	/** Паравая граница ракетки.*/
	qreal right() const;
signals:
	void coordChanged();
	void widthChanged();
	void heightChanged();
private:
	/** Размеры и положение ракетки.*/
	QRectF m_rect;
};

#endif // RACKET_H
