#include <iostream>

extern "C" {

// Provided by the rust library implementation.
void library_print_message();

}  // extern "C"

int main() {
  std::cout << "Embedder application running..." << std::endl;

  // This will call into rust.
  library_print_message();
  return 0;
}
