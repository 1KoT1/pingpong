#include "ball.h"

Ball::Ball(double radius, double x, double y, double speedX, double speedY):
	m_radius(radius),
	m_x(x),
	m_y(y),
	m_speedX(speedX),
	m_speedY(speedY)
{
}

Ball::Ball(double radius, double x, double y):
	Ball(radius, x, y, 0, 0)
{
}

double Ball::radius() const
{
	return m_radius;
}

double Ball::x() const
{
	return m_x;
}

void Ball::setX(double x)
{
	m_x = x;
}

double Ball::y() const
{
	return m_y;
}

void Ball::setY(double y)
{
	m_y = y;
}

double Ball::speedX() const
{
	return m_speedX;
}

void Ball::setSpeedX(double speedX)
{
	m_speedX = speedX;
}

double Ball::speedY() const
{
	return m_speedY;
}

void Ball::setSpeedY(double speedY)
{
	m_speedY = speedY;
}
