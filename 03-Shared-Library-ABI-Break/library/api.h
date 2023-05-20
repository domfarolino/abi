#include <string>
#include <vector>

namespace library {

// Inspired by https://www.youtube.com/watch?v=DZ93lP1I7wU.
class Point {
 public:
  Point() = default;
  void SetX(int);
  void SetY(int);
  void Print() const;

 private:
  int x_ = 0;
  int y_ = 0;
};

std::vector<Point> GetPoints();

};  // namespace library
