#include <iostream>
#include <fstream>
#include <twothreetree/twoThreeTree.h>
#include <inputDict.h>
#include <keySumm.h>
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
  std::string direction(argv[1]);
  dimkashelk::KeySumm keySumm;
  if (direction == "ascending")
  {
    dict.traverse_lnr(keySumm);
  }
  else if (direction == "descending")
  {
    dict.traverse_rnl(keySumm);
  }

  return 0;
}
