#include <functional>
#include <algorithm>
#include <numeric>

#include "fig.hpp"

using namespace std::placeholders;

bool konovalova::Point::operator==(const Point &other) const
{
    return x == other.x && y == other.y;
}

bool konovalova::Point::operator!=(const Point &other) const
{
    return x != other.x || y != other.y;
}

bool konovalova::Point::operator<(const Point &other) const
{
    if (x == other.x) return y < other.y;
    return x < other.x;
}

bool konovalova::Polygon::operator==(const Polygon &other) const
{
    if (points.size() != other.points.size()) return false;

    auto other_pnt = other.points.begin();
    auto testFunc = [&other_pnt] (const Point &pnt)
    {
        bool result = pnt == *other_pnt;
        other_pnt++;
        return result;
    };
    return std::all_of(points.begin(), points.end(), testFunc);
}

bool konovalova::Polygon::operator<(const Polygon &other) const
{
    return area() < other.area();
}