#ifndef SPBSPU_LABS_2023_AADS_904_A_STACK_H
#define SPBSPU_LABS_2023_AADS_904_A_STACK_H
#include <cstddef>
#include <stdexcept>
#include "nodeOfDataClass.h"
namespace dimkashelk
{
  template < typename T >
  class Stack
  {
  public:
    Stack():
      begin_(nullptr)
    {}
    ~Stack()
    {
      while (begin_)
      {
        drop();
      }
    }
    void push(T rhs)
    {
      auto *node = new details::NodeOfDataClass< T >(rhs);
      node->next = begin_;
      begin_ = node;
    }
    T drop()
    {
      if (empty())
      {
        throw std::logic_error("Check");
      }
      T data = begin_->data;
      auto *node = begin_;
      begin_ = begin_->next;
      delete node;
      return data;
    }
    bool empty() const
    {
      return begin_ == nullptr;
    }
  private:
    details::NodeOfDataClass< T > *begin_;
  };
}
#endif