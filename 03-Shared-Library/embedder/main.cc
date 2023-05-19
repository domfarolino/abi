#include <iostream>

#include "../library/api.h"

int main() {
  static LibraryAPI lib_api = {sizeof(lib_api)};
  GetLibraryAPI(&lib_api);

  std::cout << "Embedder is about to call Library1()" << std::endl;
  lib_api.Library1();
  std::cout << "Embedder is about to call Library2()" << std::endl;
  lib_api.Library2();
}
