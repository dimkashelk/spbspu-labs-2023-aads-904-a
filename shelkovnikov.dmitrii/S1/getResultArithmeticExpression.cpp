#include "getResultArithmeticExpression.h"
#include <limits>
#include <stdexcept>
#include <stack.h>
#include <overflow_add.h>
namespace
{
  namespace
  {
    bool isOverMult(long long first, long long second)
    {
      return (first > max_long_long / second) && ((first > 0 && second > 0) || (first < 0 && second < 0));
    }
    bool isUnderMult(long long first, long long second)
    {
      return (first < min_long_long / second) && ((first > 0 && second < 0) || (first < 0 && second > 0));
    }
  }
  bool isOverflowedMult(long long first, long long second)
  {
    return isOverMult(first, second) || isUnderMult(first, second);
  }
  long long getResult(long long first, long long second, dimkashelk::Operator oper)
  {
    if (oper.isAdd())
    {
      if (isOverflowedAdd(first, second))
      {
        throw std::logic_error("Overflow");
      }
      return first + second;
    }
    if (oper.isSubtraction())
    {
      if (isOverflowedAdd(first, second))
      {
        throw std::logic_error("Overflow");
      }
      return first - second;
    }
    if (oper.isMultiplication())
    {
      if (isOverflowedMult(first, second))
      {
        throw std::logic_error("Overflow");
      }
      return first * second;
    }
    if (oper.isDivision())
    {
      if (second == 0)
      {
        throw std::logic_error("Division by 0");
      }
      return first / second;
    }
    if (oper.isRemainder())
    {
      if (first > 0)
      {
        return first % second;
      }
      else
      {
        return second - (-first) % second;
      }
    }
    throw std::logic_error("Not supported this operator");
  }
}
long long dimkashelk::getResultArithmeticExpression(Queue< PartOfArithExpr > &polandExpression)
{
  namespace dsk = dimkashelk;
  dsk::Stack< dsk::PartOfArithExpr > remains;
  while (!polandExpression.empty())
  {
    dsk::PartOfArithExpr p = polandExpression.front();
    polandExpression.popFront();
    if (p.isNumber())
    {
      remains.pushFront(p);
    }
    else
    {
      dsk::PartOfArithExpr p2 = remains.front();
      remains.popFront();
      dsk::PartOfArithExpr p1 = remains.front();
      remains.popFront();
      remains.pushFront(dsk::PartOfArithExpr(getResult(p1.getOperand(), p2.getOperand(), p.getOperator())));
    }
  }
  auto res = remains.front().getOperand();
  remains.popFront();
  return res;
}
