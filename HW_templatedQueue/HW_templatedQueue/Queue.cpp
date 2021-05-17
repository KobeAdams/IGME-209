#include "Queue.h"
#include <iostream>
Queue::Queue()
{
	entries = 0;
	size = 4;
	content = new size_t[size];
	for (int i = 0; i < size; i++)
	{
		content[i] = NULL;
	}
}

Queue& Queue::operator= (Queue& original)
{
	Queue* temp= new Queue(original);
	return *temp;
}

Queue::Queue(Queue& origin)
{
	size = 4;
	entries = origin.getSize();
	while (size < entries)
	{
		size *= 2;
	}
	for (int i = 0; i < entries; i++)
	{
		content[i] = origin.content[i];
	}
	if (size > entries)
	{
		for (int i = entries; i < size;i++)
		{
			content[i] = NULL;
		}
	}
}

void Queue::push(size_t obj)
{
	if (size = entries)
	{
		size_t* temp = new size_t[size * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = content[i];
		}
		size *= 2;
		for (int i = entries - 1; i < size * 2; i++)
		{
			temp[i] = NULL;
		}
		delete[] content;
		content = temp;
	}
	for (int i = 0; i < size; i++)
	{
		if (content[i] == NULL)
		{
			content[i] = obj;
		}
	}
	entries++;
}

void Queue::pop(size_t obj)
{
	size_t* temp = new size_t[size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = content[i + 1];
	}
	temp[size - 1] = NULL;
	delete[] content;
	content = temp;
}
void Queue::print()
{
	for (int i = 0; i < entries; i++)
	{
		std::cout << content[i] << " ";
	}
	std::cout << "/n";
}

int Queue::getSize()
{
	return entries;
}

bool Queue::isEmpty()
{
	if (entries == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
