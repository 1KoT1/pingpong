#include "racket.h"

Racket::Racket(qreal width, qreal height, qreal x, qreal y, QObject *parent):
	m_rect(QRectF(x, y, width, height)),
	QObject(parent)
{
}

qreal Racket::width() const
{
	return m_rect.width();
}

qreal Racket::height() const
{
	return m_rect.height();
}

qreal Racket::x() const
{
	return m_rect.x();
}

void Racket::setX(qreal x)
{
	setCoordinates(QPointF(x, y()));
}

qreal Racket::y() const
{
	return m_rect.y();
}

void Racket::setY(qreal y)
{
	setCoordinates(QPointF(x(), y));
}

const QPointF &Racket::coordinates() const
{
	return m_rect.topLeft();
}

void Racket::setCoordinates(QPointF coordinates)
{
	if(m_rect.topLeft() != coordinates)
	{
		m_rect.moveTo(coordinates);
		emit coordChanged();
	}
}

qreal Racket::bottom() const
{
	return m_rect.bottom();
}

qreal Racket::right() const
{
	return m_rect.right();
}
