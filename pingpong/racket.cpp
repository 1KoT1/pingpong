#include "racket.h"

Racket::Racket(double width, double height, double x, double y, QObject *parent):
	m_width(width),
	m_height(height),
	m_x(x),
	m_y(y),
	QObject(parent)
{
}

double Racket::width() const
{
	return m_width;
}

double Racket::height() const
{
	return m_height;
}

double Racket::x() const
{
	return m_x;
}

void Racket::setX(double x)
{
	if(m_x != x)
	{
		m_x = x;
		emit xChanged();
	}
}

double Racket::y() const
{
	return m_y;
}

void Racket::setY(double y)
{
	if(m_y != y)
	{
		m_y = y;
		emit xChanged();
	}
}
