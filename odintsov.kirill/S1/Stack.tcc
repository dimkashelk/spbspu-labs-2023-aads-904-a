#include <stdexcept>

template< typename T >
odintsov::Stack< T >::Stack():
  head_(nullptr),
  tail_(nullptr)
{}

template< typename T >
odintsov::Stack< T >::~Stack()
{
  while (!empty()) {
    Node* oldTail = tail_;
    tail_ = tail_->prev;
    delete oldTail;
  }
}

template< typename T >
T& odintsov::Stack< T >::tail()
{
  return const_cast< T& >(const_cast< const Stack< T >* >(this)->tail());
}

template< typename T >
const T& odintsov::Stack< T >::tail() const
{
  if (empty()) {
    throw std::runtime_error("Attempt to get tail of empty stack");
  }
  return tail_->data;
}

template< typename T >
void odintsov::Stack< T >::push(const T& data)
{
  push(new Node{data, tail_});
}

template< typename T >
void odintsov::Stack< T >::push(T&& data)
{
  push(new Node{data, tail_});
}

template< typename T >
void odintsov::Stack< T >::push(Node* n)
{
  if (empty()) {
    head_ = n;
  }
  tail_ = n;
}

template< typename T >
void odintsov::Stack< T >::pop()
{
  if (empty()) {
    throw std::runtime_error("Attempt to pop empty stack");
  }
  Node* oldTail = tail_;
  tail_ = tail_->prev;
  if (!tail_) {
    head_ = nullptr;
  }
  delete oldTail;
}

template< typename T >
bool odintsov::Stack< T >::empty() const
{
  return !tail_ || !head_;
}
