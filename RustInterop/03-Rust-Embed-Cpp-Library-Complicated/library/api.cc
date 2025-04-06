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
  // This is a common pattern used in C/C++ APIs to handle versioning and
  // backwards compatibility, especially in shared libraries. We include the
  // size here so that as the library evolves over time and new fields are
  // added, callers can verify the version of the API that they're getting.
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

    // Copy only up to version 0 API size, and no more than what embedder
    // requested.
    //   1. If the embedder is "older" and requests a smaller version of the
    //      library, we can't write more into the `api` pointer than the
    //      embedder expects, because we'd be overflowing its memory. This lets
    //      us to give the embedder the view of the API that they request.
    //   2. If the embedder is "newer", and requests a larger version of this
    //      library, then the embedder is responsible for checking `kCurrentAPI`
    //      to confirm the version/size of the library that they're *actually*
    //      going to get; we additionally warn the embedder, and write only the
    //      amount of memory that this version of the library can write.
    //
    // Apparently this is similar to how other stable ABIs work, like Vulkan's
    // `vkEnumerateInstanceVersion()`.
    size_t copy_size = std::min(requested_size, kVersion0APISize);
    memcpy(api, &kCurrentAPI, copy_size);
}

}  // extern "C"
