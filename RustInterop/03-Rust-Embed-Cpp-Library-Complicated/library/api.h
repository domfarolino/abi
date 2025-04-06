#include <stddef.h>

// Use C linkage for ABI stability.
extern "C" {

struct LibraryAPI {
  // See the implementation for notes about this member.
  size_t size;

  void(*PrintString)(char* str);
  int(*AddNumbers)(int a, int b);
};

// Called by our embedder to get a concerete implementation of the above
// API-exposed function table, i.e., an instance of that table where the
// function pointers point to concrete function implementations that are
// internal to this library.
void GetLibraryAPI(LibraryAPI* api, size_t requested_size);

}  // extern "C"
