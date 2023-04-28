#include "convertstringtoinfix.hpp"
#include <string>
#include <cstring>
#include <sstream>
#include "queue.hpp"

Queue< std::string > convertStringToInfix(std::string str)
{
  Queue< std::string > infix_queue;
  std::stringstream string_stream(str); 
  std::string token;
  while (string_stream >> token)
  {
    infix_queue.push(token);
  }
  return infix_queue;
}

