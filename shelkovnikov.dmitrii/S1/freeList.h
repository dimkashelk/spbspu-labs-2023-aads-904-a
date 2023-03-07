#ifndef SPBSPU_LABS_2023_AADS_904_A_FREELIST_H
#define SPBSPU_LABS_2023_AADS_904_A_FREELIST_H
#include "nodeOfDataClass.h"
namespace details
{
  template< typename T >
  void freeList(NodeOfDataClass< T > *start)
  {
    while (start)
    {
      auto node = start;
      start = start->next;
      delete node;
    }
  }
}
#endif