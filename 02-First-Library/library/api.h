#include <stddef.h>

// Use C linkage for ABI stability.
extern "C" {

struct LibraryAPI {
  size_t size;

  void(*Library1)();
  void(*Library2)();
};

// Called by our embedder to get a concerete implementation of the above
// API-exposed function table, i.e., an instance of that table where the
// function pointers point to concrete function implementations that are
// internal to this library.
void GetLibraryAPI(LibraryAPI* embedder_api_ptr);

}  // namespace "C"
