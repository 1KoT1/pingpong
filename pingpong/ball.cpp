#include "ball.h"

Ball::Ball(qreal radius, qreal x, qreal y, qreal speedX, qreal speedY, QObject *parent):
	QObject(parent),
	m_radius(radius),
	m_coord(x, y),
	m_speed(QPointF(speedX, speedY))
{
}

Ball::Ball(qreal radius, qreal x, qreal y, QObject *parent):
	Ball(radius, x, y, 0, 0, parent)
{
}

qreal Ball::radius() const
{
	return m_radius;
}

qreal Ball::x() const
{
	return m_coord.x();
}

void Ball::setX(qreal x)
{
	if(m_coord.x() != x)
	{
		m_coord.setX(x);
		emit coordChanged();
	}
}

qreal Ball::y() const
{
	return m_coord.y();
}

void Ball::setY(qreal y)
{
	if(m_coord.y() != y)
	{
		m_coord.setY(y);
		emit coordChanged();
	}
}

void Ball::setCoordinates(QPointF coord)
{
	if(m_coord != coord)
	{
		m_coord = coord;
		emit coordChanged();
	}
}

const QPointF &Ball::coordinates() const
{
	return m_coord;
}

qreal Ball::speedX() const
{
	return m_speed.x();
}

void Ball::setSpeedX(qreal speedX)
{
	m_speed.setX(speedX);
}

qreal Ball::speedY() const
{
	return m_speed.y();
}

void Ball::setSpeedY(qreal speedY)
{
	m_speed.setY(speedY);
}

const QPointF &Ball::speed() const
{
	return m_speed;
}
