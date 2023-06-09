#include <iostream>
#include <fstream>
#include <twothreetree/twoThreeTree.h>
#include <inputDict.h>
#include <summator.h>
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
  auto dict = dimkashelk::inputDict(in);
  std::string direction(argv[1]);
  dimkashelk::Summator summator;
  if (direction == "ascending")
  {
    dict.traverse_lnr(summator);
  }
  else if (direction == "descending")
  {
    dict.traverse_rnl(summator);
  }
  else if (direction == "breadth")
  {
    dict.traverse_breadth(summator);
  }
  std::cout << summator.getKeySum() << " " << summator.getValueSum() << '\n';
  return 0;
}
