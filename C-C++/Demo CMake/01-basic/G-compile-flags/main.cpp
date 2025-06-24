#include <iostream>

int main(int argc, char *argv[])
{
#ifdef EX1
  std::cout << "Hello EX1!" << std::endl;
#endif

#ifdef EX2
  std::cout << "Hello EX2!" << std::endl;
#endif

   return 0;
}
