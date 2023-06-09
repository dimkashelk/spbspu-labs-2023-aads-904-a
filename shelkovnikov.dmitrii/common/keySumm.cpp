#include "keySumm.h"
dimkashelk::KeySumm::KeySumm():
  result(0)
{}
void dimkashelk::KeySumm::operator()(const std::pair< const int, std::string > &key_value)
{
  result += key_value.first;
}
