#include "summator.h"
#include <stdexcept>
#include "overflow_add_mult.h"
dimkashelk::Summator::Summator():
  keySumm_(0),
  valueSumm_()
{}
void dimkashelk::Summator::operator()(const std::pair< const int, std::string > &key_value)
{
  if (isOverflowedAdd(keySumm_, key_value.first))
  {
    throw std::overflow_error("Overflow");
  }
  keySumm_ += key_value.first;
  if (valueSumm_.empty())
  {
    valueSumm_ = key_value.second;
  }
  else
  {
    valueSumm_ += " " + key_value.second;
  }
}
long long dimkashelk::Summator::getKeySum()
{
  return keySumm_;
}
std::string dimkashelk::Summator::getValueSum()
{
  return valueSumm_;
}
