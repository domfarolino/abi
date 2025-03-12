#include "api.h"

#include <iostream>
#include <algorithm>

namespace {

void PrintString(char* str) {
  std::cout << "[C library]: Embedder called PrintString(): " << str << std::endl;
}
int AddNumbers(int a, int b) {
  std::cout << "[C library]: Embedder called AddNumbers(" << a << ", " << b << "): " << a + b << std::endl;
  return a + b;
}

constexpr LibraryAPI kCurrentAPI = {
    sizeof(kCurrentAPI),
    PrintString,
    AddNumbers,
};

constexpr size_t kVersion0APISize = offsetof(LibraryAPI, AddNumbers) + sizeof(kCurrentAPI.AddNumbers);

}  // namespace

extern "C" {

void GetLibraryAPI(LibraryAPI* api, size_t requested_size) {
    if (requested_size > kVersion0APISize) {
        std::cerr << "Warning: embedder is requesting a later version of this library "
                  << "than what is supported. Requested API size of " << requested_size
                  << " but this library only supports the version 0 API size of (" 
                  << kVersion0APISize << ")" << std::endl;
    }
    // Copy only up to version 0 API size, and no more than what embedder requested
    size_t copy_size = std::min(requested_size, kVersion0APISize);
    memcpy(api, &kCurrentAPI, copy_size);
}

}  // extern "C"
