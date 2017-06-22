
#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

/*****************************************************************************/

#include "point.hpp"

/*****************************************************************************/


class Rectangle
{

	Point TopLeft;
	Point TopRight;
	Point BottomLeft;
	Point BottomRight;

	double Width;
	double Height;

public:

	Rectangle(Point _TL, Point _BR);
	Rectangle(Point _TL, double _width, double _height);
	
	Point getTopLeft() const;
	Point getTopRight() const;
	Point getBottomLeft() const;
	Point getBottomRight() const;

	double getWidth() const;
	double getHeight() const;

	double getPerimeter() const;
	double getArea() const;

	bool operator == (const Rectangle & rc) const;
	bool operator != (const Rectangle & rc) const;

	bool contains(Point _p);
	bool contains(Point _p1, Point _p2);
	bool intersects(const Rectangle & _r);
	bool covers(const Rectangle & _r);


};

/*****************************************************************************/

inline Point 
Rectangle::getTopLeft() const
{
	return TopLeft;
}

/*****************************************************************************/

inline Point
Rectangle::getTopRight() const
{
	return TopRight;
}

/*****************************************************************************/

inline Point
Rectangle::getBottomLeft() const
{
	return BottomLeft;
}

/*****************************************************************************/


inline Point
Rectangle::getBottomRight() const
{
	return BottomRight;
}

/*****************************************************************************/

inline double
Rectangle::getWidth() const
{
	return Width;
}

/*****************************************************************************/

inline double
Rectangle::getHeight() const
{
	return Height;
}

inline double
Rectangle::getPerimeter() const
{
	return (Width + Height) * 2;
}

inline double
Rectangle::getArea() const
{
	return Width * Height;
}
/*****************************************************************************/
#endif //  _RECTANGLE_HPP_