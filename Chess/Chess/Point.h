#ifndef POINT_H_
#define POINT_H_


class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

public:

	int getPointX();
	int getPointY();
	void setPointX(int x);
	void setPointY(int y);

private:
	int m_x, m_y;
};

#endif // !POINT_H_
