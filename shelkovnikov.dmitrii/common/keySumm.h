#ifndef SPBSPU_LABS_2023_AADS_904_A_KEYSUMM_H
#define SPBSPU_LABS_2023_AADS_904_A_KEYSUMM_H
#include <string>
namespace dimkashelk
{
  struct KeySumm
  {
    KeySumm();
    void operator()(const std::pair< const int, std::string > &key_value);
    int result;
  };
}
#endif
