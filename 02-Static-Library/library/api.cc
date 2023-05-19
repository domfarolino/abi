#include "api.h"

#include <iostream>

namespace library {

void Library::Library1() {
  std::cout << "Embedder called Library1()" << std::endl;
}
void Library::Library2() {
  std::cout << "Embedder called Library2()" << std::endl;
}

}  // namespace library
