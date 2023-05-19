#include "api.h"

#include <iostream>

void Library1() {
  std::cout << "Embedder called Library1()" << std::endl;
}
void Library2() {
  std::cout << "Embedder called Library2()" << std::endl;
}

constexpr LibraryAPI kCurrentAPI = {
    sizeof(kCurrentAPI),
    Library1,
    Library2,
};

constexpr size_t kVersion0APISize = offsetof(LibraryAPI, Library2) + sizeof(kCurrentAPI.Library2);

// TODO(domfarolino): Do we need some sort of export thing here for the shared library?
void GetLibraryAPI(LibraryAPI* embedder_api_ptr) {
  memcpy(embedder_api_ptr, &kCurrentAPI, kVersion0APISize);
}
