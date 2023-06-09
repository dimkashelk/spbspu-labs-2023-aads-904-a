#include <iostream>
#include <fstream>
#include "twothreetree/twoThreeTree.h"
#include "inputDict.h"
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
  auto dict = dimkashelk::inputDict(std::cin);
  return 0;
}
