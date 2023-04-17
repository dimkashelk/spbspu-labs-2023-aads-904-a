#include "partOfArithmeticExpression.h"
#include <stdexcept>
namespace
{
  bool checkDigit(const std::string &str)
  {
    return str.find_first_not_of("0123456789") == std::string::npos;
  }
  bool checkBracket(const std::string &str)
  {
    try
    {
      dimkashelk::Parenthesis bracket(str[0]);
      return true;
    }
    catch (...)
    {
      return false;
    }
  }
}
dimkashelk::PartOfArithExpr::element::element(long long o):
  operand_(o)
{}
dimkashelk::PartOfArithExpr::element::element(const std::string &str)
{
  if (checkDigit(str))
  {
    operand_ = std::stoll(str);
  }
  else
  {
    try
    {
      bracket_ = Parenthesis(str[0]);
    }
    catch (...)
    {
      operator_ = Operator(str[0]);
    }
  }
}
dimkashelk::PartOfArithExpr::PartOfArithExpr(const std::string &str):
  isNumber_(checkDigit(str)),
  isParenthesis_(checkBracket(str)),
  element(str)
{}
dimkashelk::PartOfArithExpr::PartOfArithExpr(long long number):
  isNumber_(true),
  isParenthesis_(false),
  element(number)
{}
dimkashelk::PartOfArithExpr::PartOfArithExpr(const PartOfArithExpr &part):
  isNumber_(part.isNumber_),
  isParenthesis_(part.isParenthesis_),
  element(part.element)
{}
dimkashelk::PartOfArithExpr::PartOfArithExpr(PartOfArithExpr &&part):
  isNumber_(part.isNumber_),
  isParenthesis_(part.isParenthesis_),
  element(part.element)
{}
dimkashelk::PartOfArithExpr &dimkashelk::PartOfArithExpr::operator=(const PartOfArithExpr &part)
{
  isNumber_ = part.isNumber_;
  isParenthesis_ = part.isParenthesis_;
  element = part.element;
  return *this;
}
dimkashelk::PartOfArithExpr &dimkashelk::PartOfArithExpr::operator=(dimkashelk::PartOfArithExpr &&part)
{
  isNumber_ = part.isNumber_;
  isParenthesis_ = part.isParenthesis_;
  element = part.element;
  return *this;
}
bool dimkashelk::PartOfArithExpr::isDigit() const
{
  return isNumber_;
}
bool dimkashelk::PartOfArithExpr::isBracket() const
{
  return isParenthesis_;
}
dimkashelk::Operator dimkashelk::PartOfArithExpr::getOperator() const
{
  return element.operator_;
}
dimkashelk::Parenthesis dimkashelk::PartOfArithExpr::getBracket() const
{
  return element.bracket_;
}
long long dimkashelk::PartOfArithExpr::getOperand() const
{
  return element.operand_;
}
bool dimkashelk::isGreaterPriority(const PartOfArithExpr &lhs, const PartOfArithExpr &rhs)
{
  if (lhs.isDigit() || rhs.isDigit() || lhs.isBracket() || rhs.isBracket())
  {
    throw std::logic_error("Must be operator, not operand or brackets");
  }
  if (lhs.getOperator().isAdd() || lhs.getOperator().isSubtraction())
  {
    return rhs.getOperator().isMultiplication() || rhs.getOperator().isDivision() || rhs.getOperator().isRemainder();
  }
  return false;
}
