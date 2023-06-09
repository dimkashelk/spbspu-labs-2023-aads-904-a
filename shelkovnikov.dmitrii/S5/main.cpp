#include <iostream>
#include <fstream>
#include "twothreetree/twoThreeTree.h"
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cout << "Check parameters";
    return 1;
  }
  std::ifstream in(argv[2]);
  if (!in)
  {
    std::cout << "Check file";
    return 2;
  }
  using dict_type = dimkashelk::TwoThreeTree< int, std::string, std::less< > >;
  dict_type data;
  int key = 0;
  std::string value;
  while (in)
  {
    in >> key >> value;
    if (!in)
    {
      break;
    }
    data.insert(key, value);
  }
  return 0;
}
