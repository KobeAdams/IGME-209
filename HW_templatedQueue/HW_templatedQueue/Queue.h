#pragma once
class Queue
{
public:
	Queue();
	Queue(Queue& origin);
	Queue& operator= (Queue& original);
	~Queue(); 

	void push(size_t obj);
	void pop(size_t obj);
	void print();
	int getSize();
	bool isEmpty();
	size_t* content;
private:
	
	int size;
	int entries;
};

