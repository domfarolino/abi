#include <stddef.h>

// Use C linkage for ABI stability.
extern "C" {

/*
struct EmbedderAPI {
  size_t size;

  // Called by library.
  void(Embedder1)();
  void(Embedder2)();
};
*/

struct LibraryAPI {
  size_t size;

  void(*Library1)();
  void(*Library2)();
};

void GetLibraryAPI(LibraryAPI* embedder_api_ptr);

}  // namespace "C"
