#include "inputDict.h"
#include <istream>
dimkashelk::TwoThreeTree< long long, std::string, std::less< >> dimkashelk::inputDict(std::istream &in)
{
  using dict_type = dimkashelk::TwoThreeTree< long long, std::string, std::less< > >;
  dict_type data;
  long long key = 0;
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
  return data;
}
