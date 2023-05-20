#include <algorithm>
#include <iostream>
#include <vector>

#include "api.h"

LibraryAPI::LibraryAPI() {
  std::cout << "LibraryAPI::ctor() size:" << sizeof(this) << std::endl;
}
void LibraryAPI::SortVector(std::vector<int>& in_vec) {
  std::sort(in_vec.begin(), in_vec.end());
  std::cout << "Embedder called SortVector()" << std::endl;
}
std::string LibraryAPI::GetString() {
  std::cout << "Embedder called GetString()" << std::endl;

  private_1_ = "";
  private_3_ = {};
  return "This is a medium sized string";
}
