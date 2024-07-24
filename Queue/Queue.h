#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <array>
#include <iostream>

namespace Queue
{
	template <typename Type>
	class Queue
	{
	protected:
		virtual void enqueue(const Type&) = 0;
		virtual void dequeue() = 0;
		virtual Type first() = 0;
		virtual Type back() = 0;
		virtual bool isFull();
		virtual bool isEmpty();
	};
}

#endif // !QUEUE_H
