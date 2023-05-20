#include <string>
#include <vector>

class LibraryAPI {
 public:
  LibraryAPI();

  void SortVector(std::vector<int>&);
  std::string GetString();

 private:
  std::string private_1_;
  std::vector<int> private_3_;
};
