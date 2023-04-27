#include <iostream>
#include <fstream>
#include "forward-list.hpp"

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "There is no file in parameters\n";
    return 1;
  }
  std::ifstream input(argv[1]);
  if (!input.is_open())
  {
    std::cerr << "The file doesn't opened\n";
    return 1;
  }
  chemodurov::ForwardList< int > list {0, 1, 2, 3, 4, 5};
  list.reverse();
  return 0;
}
