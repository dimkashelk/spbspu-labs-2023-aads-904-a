#ifndef SPBSPU_LABS_2023_AADS_904_A_KEYSUMM_H
#define SPBSPU_LABS_2023_AADS_904_A_KEYSUMM_H
#include <string>
namespace dimkashelk
{
  class Summator
  {
  public:
    Summator();
    void operator()(const std::pair< const int, std::string > &key_value);
    long long getKeySum();
    std::string getValueSum();
  private:
    long long keySumm_;
    std::string valueSumm_;
  };
}
#endif
