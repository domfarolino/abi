#include <iostream>

#include "../library/api.h"

int main() {
  std::cout << "Embedder application booting up; detecting sizeof(LibraryAPI): " << sizeof(LibraryAPI) << std::endl;
  LibraryAPI lib_api;

  std::vector<int> vector = {42, 24, 2, 3, 6, 5, 32, 24, 5};
  std::cout << "Embedder is about to call SortVector()" << std::endl;
  lib_api.SortVector(vector);
  std::cout << "Embedder is about to call GetString()" << std::endl;
  std::string str = lib_api.GetString();

  for (const int& n : vector) {
    std::cout << n << ", ";
  }
  std::cout << std::endl;

  std::cout << str << std::endl;
  return 0;
}
