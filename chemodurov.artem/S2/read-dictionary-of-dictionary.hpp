#ifndef S2_READ_DICTIONARY_OF_DICTIONARY_HPP
#define S2_READ_DICTIONARY_OF_DICTIONARY_HPP
#include <string>
#include "dictionary.hpp"

namespace chemodurov
{
  Dictionary< std::string, Dictionary< int, std::string, std::less< > >, std::less< > > readDictionaryOfDictionary(std::istream & in);
}

#endif
