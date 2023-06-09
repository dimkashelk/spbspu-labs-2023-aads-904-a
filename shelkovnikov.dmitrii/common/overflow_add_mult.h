#ifndef SPBSPU_LABS_2023_AADS_904_A_OVERFLOW_ADD_MULT_H
#define SPBSPU_LABS_2023_AADS_904_A_OVERFLOW_ADD_MULT_H
#include <limits>
namespace
{
  constexpr long long max_long_long = std::numeric_limits< long long >::max();
  constexpr long long min_long_long = std::numeric_limits< long long >::min();
  namespace
  {
    bool isOverAdd(long long first, long long second)
    {
      return first > 0 && second > 0 && second > (max_long_long - first);
    }
    bool isUnderAdd(long long first, long long second)
    {
      return first < 0 && second < 0 && first < (min_long_long - second);
    }
    bool isOverMult(long long first, long long second)
    {
      return (first > max_long_long / second) && ((first > 0 && second > 0) || (first < 0 && second < 0));
    }
    bool isUnderMult(long long first, long long second)
    {
      return (first < min_long_long / second) && ((first > 0 && second < 0) || (first < 0 && second > 0));
    }
  }
  bool isOverflowedAdd(long long first, long long second)
  {
    return isOverAdd(first, second) || isUnderAdd(first, second);
  }
  bool isOverflowedMult(long long first, long long second)
  {
    return isOverMult(first, second) || isUnderMult(first, second);
  }
}

#endif
