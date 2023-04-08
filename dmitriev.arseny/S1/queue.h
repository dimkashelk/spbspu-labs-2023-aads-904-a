#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
#include <iomanip>

template< typename T >
class Queue
{
public:
	Queue();
	~Queue();

	Queue(const Queue< T >& otherQueue);
	Queue(Queue< T >&& otherQueue);

	Queue< T >& operator=(const Queue< T >& otherQueue);
	Queue< T >& operator=(Queue< T >&& otherQueue);

	void push(T rhs);
	void popBack();
	T getTopData();

	T unsafeGetTopAndPop();

	bool isEmpty();

private:
	List< T >* head;
	List< T >* tail;

	void clear();

};

template<typename T>
Queue<T>::Queue() :
	head(nullptr),
	tail(nullptr)
{

}

template<typename T>
Queue<T>::~Queue()
{
	clear();
}

template<typename T>
Queue<T>::Queue(const Queue<T>& otherQueue) :
	head(nullptr),
	tail(nullptr)
{
	if (otherQueue.head != nullptr)
	{
		List< T >* otherTail = otherQueue.head;
		push(otherTail->data);
		otherTail = otherTail->otherList;
		while (otherTail != nullptr)
		{
			tail->otherList = new List< T >(otherTail->data);
			tail = tail->otherList;
			otherTail = otherTail->otherList;
		}
	}
}

template<typename T>
Queue<T>::Queue(Queue<T>&& otherQueue) :
	head(otherQueue.head),
	tail(otherQueue.tail)
{
	otherQueue.head = nullptr;
	otherQueue.tail = nullptr;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& otherQueue)
{
	if (this == &otherQueue)
	{
		return *this;
	}
	Queue< T > newQueue(otherQueue);
	clear();
	head = newQueue.head;
	tail = newQueue.tail;

	newQueue.head = nullptr;
	newQueue.tail = nullptr;

	return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& otherQueue)
{
	if (this == &otherQueue)
	{
		return *this;
	}
	clear();
	head = otherQueue.head;
	tail = otherQueue.tail;

	otherQueue.head = nullptr;
	otherQueue.tail = nullptr;

	return *this;
}

template< typename T >
void Queue< T >::push(T rhs)
{
	if (head == nullptr)
	{
		head = new List< T >(rhs);
		tail = head;
	}
	else
	{
		tail->otherList = new List< T >(rhs);
		tail = tail->otherList;
	}
}

template< typename T >
void Queue< T >::popBack()
{
	if (head == nullptr)
	{
		throw std::underflow_error("underflow_error");
	}
	List< T >* newHead = head->otherList;
	delete head;

	head = newHead;
}

template<typename T>
T Queue<T>::getTopData()
{
	if (head == nullptr)
	{
		throw std::underflow_error("underflow_error");
	}
	return head->data;
}

template<typename T>
T Queue<T>::unsafeGetTopAndPop()
{
	T currentData = getTopData();
	popBack();

	return currentData;
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	return head == nullptr;
}

template<typename T>
void Queue<T>::clear()
{
	while (!isEmpty())
	{
		popBack();
	}
}

#endif
