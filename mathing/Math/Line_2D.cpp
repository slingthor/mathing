#include "pch.h"
#include "Line_2D.h"

float math::line_2D::length()
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
