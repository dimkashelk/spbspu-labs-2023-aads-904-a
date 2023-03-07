#ifndef SPBSPU_LABS_2023_AADS_904_A_GETQUEUEOFARITHMETICEXPRESSION_H
#define SPBSPU_LABS_2023_AADS_904_A_GETQUEUEOFARITHMETICEXPRESSION_H
#include <string>
#include "queue.h"
#include "partOfArithmeticExpression.h"
#include "parser.h"
namespace dimkashelk
{
  Queue< PartOfArithmeticExpression > getQueueOfArithmeticExpression(std::string element)
  {
    Parser parser(element);
    Queue< PartOfArithmeticExpression > data;
    while (parser.hasNext())
    {
      data.push(PartOfArithmeticExpression(parser()));
    }
    return data;
  }
}
#endif