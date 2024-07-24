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
		static constexpr std::size_t CAPACITY = 10000;

	protected:
		virtual void enqueue(const Type&) = 0;
		virtual void dequeue() = 0;
		virtual Type front() const = 0;
		virtual Type back() const = 0;
		virtual bool isFull() const = 0;
		virtual bool isEmpty() const = 0;
	};

	template <typename Type>
	class queueArray : public queue<Type>
	{
	private:
		std::size_t size;
		std::size_t frontIndex;
		std::size_t backIndex;

		std::array<Type, queue<Type>::CAPACITY> container;

	public:
		queueArray() : container(), size(0), frontIndex(0), backIndex(0) {}

		void enqueue(const  Type& data) override
		{
			if (isFull())
			{
				std::cerr << "Queue overflow" << std::endl;
				return;
			}

			backIndex = (backIndex + 1) % queue<Type>::CAPACITY;
			container[backIndex] = data;
			size++;
		}

		void dequeue() override 
		{
			if (isEmpty())
			{
				std::cerr << "Queue underflow" << std::endl;
				return;
			}

			container[frontIndex] = Type();
			frontIndex = (frontIndex + 1) % queue<Type>::CAPACITY;
			size--;
		}

		Type front() const override { return (!isEmpty() ? container[frontIndex + 1] : Type()); }

		Type back() const override { return (!isEmpty() ? container[backIndex] : Type()); }

		bool isFull() const override { return (size == queue<Type>::CAPACITY); }

		bool isEmpty() const override { return (size == 0); }
	};
}

#endif // !QUEUE_H
