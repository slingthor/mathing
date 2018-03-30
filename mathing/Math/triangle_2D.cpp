#include "pch.h"
#include "triangle_2D.h"

math::line_2D math::triangle_2D::aOppositeSide()
{
	return line_2D{b, c};
}

math::line_2D math::triangle_2D::bOppositeSide()
{
	return line_2D{a, c};
}

math::line_2D math::triangle_2D::cOppositeSide()
{
	return line_2D{a, b};
}

float math::triangle_2D::aAngle()
{
	return 0;
}

float math::triangle_2D::bAngle()
{
	return 0;
}

float math::triangle_2D::cAngle()
{
	return 0;
}
