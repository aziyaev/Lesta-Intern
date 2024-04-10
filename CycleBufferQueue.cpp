#include <stdexcept>

class CycleBufferQueue
{
private:
	int size;
	int count;
	int head_index;
	int tail_index;
	int* items;

public:
	CycleBufferQueue(int size) : size(size), count(0), head_index(0), tail_index(0) {
		items = new int[size];
	}

	~CycleBufferQueue() {
		delete[] items;
	}

	int getSize() const {
		return size;
	}

	int getCount() const {
		return count;
	}

	bool isEmpty() const {
		return count == 0;
	}

	bool isFull() const {
		return count == size;
	}

	int moveIndex(int index) const {
		return (index + 1) % size;
	}

	void push(int item) {
		if (isFull()) {
			throw std::runtime_error("Buffer is full");
		}

		items[head_index] = item;
		count++;
		head_index = moveIndex(head_index);
	}

	int pop() {
		if (isEmpty()) {
			throw std::runtime_error("Buffer is empty");
		}
		int item = items[tail_index];
		count--;
		tail_index = moveIndex(tail_index);
		return item;
	}
};
