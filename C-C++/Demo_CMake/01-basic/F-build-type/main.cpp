#include <iostream>

int main() {
#ifdef DEBUG_MODE
   std::cout << "Hello in debug mode!" << std::endl;
#else
   std::cout << "Hello in no-debug mode!" << std::endl;
#endif
   return 0;
}
