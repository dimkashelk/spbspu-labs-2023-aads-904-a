#ifndef SPBSPU_LABS_2023_AADS_904_A_INPUTDICT_H
#define SPBSPU_LABS_2023_AADS_904_A_INPUTDICT_H
#include "twothreetree/twoThreeTree.h"
namespace dimkashelk
{
  TwoThreeTree< int, std::string, std::less< > > inputDict(std::istream &in);
}
#endif
