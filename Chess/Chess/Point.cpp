#include "Point.h"



Point::Point()
{
}


Point::Point(int x, int y)
{
	setPointX(x);
	setPointY(y);
}

Point::~Point()
{
}

int Point::getPointX()
{
	return m_x;
}

int Point::getPointY()
{
	return m_y;
}

void Point::setPointX(int x)
{
	m_x = x;
}

void Point::setPointY(int y)
{
	m_y = y;
}
