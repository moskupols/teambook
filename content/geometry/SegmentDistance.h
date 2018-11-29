/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Status: tested
 */
#pragma once
#include "Point.h"

double segment_point_distance(Point a, Point b, Point p) {
	if (a==b) return (p-a).hypot();
	auto d = (b-a).hypot2(), t = min(d, max(.0, (p-a) * (b-a)));
	return ((p-a) * d - (b-a) * t).hypot() / d;
}
