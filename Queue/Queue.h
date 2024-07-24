#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <array>
#include <iostream>

namespace Queue
{
	template <typename Type>
	class queue
	{
	protected:
		virtual void enqueue(const Type&) = 0;
		virtual void dequeue() = 0;
		virtual Type first() const = 0;
		virtual Type back() const = 0;
		virtual bool isFull() const = 0;
		virtual bool isEmpty() const = 0;
	};

	template <typename Type>
	class queueArray
	{
	private:
		constexpr std::size_t CAPACITY;
		std::size_t size;
		std::size_t frontIndex;
		std::size_t backIndex;

		std::array<Type, CAPACITY> container;

	public:
		void enqueue(const  Type& data) override
		{
			// if ()
		}

		bool isFull() const override { return (size == CAPACITY); }

		bool isEmpty() const override { return (size == 0); }
	};
}

#endif // !QUEUE_H
