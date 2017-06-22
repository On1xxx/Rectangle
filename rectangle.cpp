
#include "rectangle.hpp"

#include <stdexcept>

/*****************************************************************************/
Rectangle::Rectangle(Point _TL, Point _BR)
	:TopLeft(_TL), BottomRight(_BR), TopRight(_BR.m_x,_TL.m_y), BottomLeft(_TL.m_x, _BR.m_y), Width(_TL.m_y - _BR.m_y), Height(_BR.m_x - _TL.m_x)
{
	if (_TL.m_x < 0 || _TL.m_y < 0 || _BR.m_x < 0 || _BR.m_y < 0 || _TL == _BR || _TL.m_y < _BR.m_y || _TL.m_x > _BR.m_x)
		throw std::logic_error("Invalid rectangle coordinates");
}

Rectangle::Rectangle(Point _TL, double _width, double _height)
	: TopLeft(_TL), BottomRight(_TL.m_x+_width,_TL.m_y-_height), TopRight(_TL.m_x+_width, _TL.m_y), BottomLeft(_TL.m_x, _TL.m_y+_height), Width(_width), Height(_height)
{
	if (Width < 0 || Height < 0 )
		throw std::logic_error("Invalid rectangle coordinates");
}


bool Rectangle::operator == (const Rectangle & _rc) const
{
	return TopLeft == _rc.TopLeft && BottomRight == _rc.BottomRight;
}

bool Rectangle::operator != (const Rectangle & _rc) const
{
	return !(*this==_rc);
}


bool Rectangle::contains(Point _p)
{
	return (_p.m_x >= BottomLeft.m_x && _p.m_x <= BottomRight.m_x) && (_p.m_y >= BottomLeft.m_y && _p.m_y <= TopLeft.m_y);
}

bool Rectangle::contains(Point _p1, Point _p2)
{
	return ((_p1.m_x > BottomLeft.m_x && _p1.m_x < BottomRight.m_x) && (_p1.m_y > BottomLeft.m_y && _p1.m_y < TopLeft.m_y))
		&& ((_p2.m_x > BottomLeft.m_x && _p2.m_x < BottomRight.m_x) && (_p2.m_y > BottomLeft.m_y && _p2.m_y < TopLeft.m_y));
}

bool Rectangle::intersects(const Rectangle & _r)
{
	return (_r.TopLeft == TopLeft || _r.TopLeft == TopRight || _r.TopLeft == BottomLeft || _r.TopLeft == BottomRight)
		|| (_r.TopRight == TopLeft || _r.TopRight == TopRight || _r.TopRight == BottomLeft || _r.TopRight == BottomRight)
		|| (_r.BottomLeft == TopLeft || _r.BottomLeft == TopRight || _r.BottomLeft == BottomLeft || _r.BottomLeft == BottomRight)
		|| (_r.BottomRight == TopLeft || _r.BottomRight == TopRight || _r.BottomRight == BottomLeft || _r.BottomRight == BottomRight);
}

bool Rectangle::covers(const Rectangle & _r)
{
	return contains(_r.TopLeft) && contains(_r.BottomRight);
}
/*****************************************************************************/