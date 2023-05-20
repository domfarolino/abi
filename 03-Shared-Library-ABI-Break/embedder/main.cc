#include <iostream>

#include "../library/api.h"

int main() {
  std::cout << "Embedder application booting up; detecting sizeof(library::Point): "
            << sizeof(library::Point) << std::endl;
  std::vector<library::Point> points = library::GetPoints();
  for (const library::Point& point : points) {
    point.Print();
  }

  return 0;
}
