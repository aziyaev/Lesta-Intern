#include <stdexcept>

class ListItem {
private:
	int data;
	ListItem* next_el;

public:
	ListItem(int data = 0, ListItem* next_el = nullptr) : data(data), next_el(next_el) {};

	ListItem* getNextEl() {
		return next_el;
	}

	void setNextEl(ListItem* next_el) {
		this->next_el = next_el;
	}

	int getData() {
		return data;
	}

	void setData(int data) {
		this->data = data;
	}
};

class CycleBufferList {
private:
	int size;
	int count;
	ListItem* head_el;
	ListItem* tail_el;

public:
	CycleBufferList(int size) : size(size), count(0), tail_el(nullptr) {
		if (size <= 0) {
			throw std::invalid_argument("Buffer size must be positive");
		}

		ListItem* item = new ListItem();
		ListItem* first_item = item;

		for (int i = 0; i < size - 1; i++) {
			item = new ListItem(0, item);
		}

		first_item->setNextEl(item);
		head_el = first_item;
		tail_el = first_item;
	}

	~CycleBufferList() {
		ListItem* current = head_el;
		while (current != nullptr) {
			ListItem* temp = current;
			current = current->getNextEl();
			delete temp;
		}
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

	void push(int el) {
		if (isFull()) {
			throw std::runtime_error("Buffer is full");
		}

		head_el->setData(el);
		count++;
		head_el = head_el->getNextEl();
	}

	int pop() {
		if (isEmpty()) {
			throw std::runtime_error("Buffer is empty");
		}

		int item = tail_el->getData();
		count--;
		tail_el = tail_el->getNextEl();

		return item;
	}
};