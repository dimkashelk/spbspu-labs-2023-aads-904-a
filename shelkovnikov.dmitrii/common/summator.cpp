#include "summator.h"
dimkashelk::Summator::Summator():
  keySumm_(0),
  valueSumm_()
{}
void dimkashelk::Summator::operator()(const std::pair< const int, std::string > &key_value)
{
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