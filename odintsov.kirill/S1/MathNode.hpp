#ifndef MATHNODE_HPP
#define MATHNODE_HPP

#include <initializer_list>
#include <iosfwd>
#include <string>

#include "Operator.hpp"

namespace odintsov {
  struct MathNode {
    enum Tag {
      Operand,
      Operator,
      Paren
    } tag;

    union Data {
      double operand;
      odintsov::Operator oper;
      char paren;
    } data;

    MathNode(Tag& t, Data& d);
    MathNode(const std::string& str);
    MathNode(std::istream& in);
  };
}

#endif
