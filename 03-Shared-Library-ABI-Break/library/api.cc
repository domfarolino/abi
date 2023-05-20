#include <algorithm>
#include <iostream>
#include <vector>

#include "api.h"

namespace library {

std::vector<Point> GetPoints() {
  std::cout << "library::GetPoints() running. sizeof(Point): " << sizeof(Point) << std::endl;
  std::vector<Point> points;

  for (int i = 0; i < 5; ++i) {
    Point point;
    point.SetX(i);
    point.SetY(i);
    points.push_back(point);
  }

  return points;
}

void Point::SetX(int x) { x_ = x; }
void Point::SetY(int y) { y_ = y; }

void Point::Print() const {
  std::cout << "(x: " << x_ << ", y: " << y_ << ")" << std::endl;
}

}  // namespace library
