#include "api.h"

#include <iostream>

extern "C" {

void Greet(const char* string) {
  std::cout << "[C library]: Hello, " << string << std::endl;
}

int AddNumbers(int a, int b) {
  std::cout << "[C library]: Adding " << a << " + " << b << ": " << a + b << std::endl;
  return a + b;
}

}  // extern "C"
