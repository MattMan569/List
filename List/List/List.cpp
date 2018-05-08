// File: List.cpp
//

#include "stdafx.h"
#include "List.h"

namespace List
{

	template <typename T>
	List<T>::List(int maximumListSize) : start(nullptr), end(nullptr)
	{
		maximumSize = maximumListSize;
	}


	template <typename T>
	List<T>::List(std::vector<T> input)
	{
		for (auto const& value : input)
		{
			// TODO
			// Add to list
		}
	}


	template <typename T>
	List<T>::List(std::string fileName, std::string delimiter)
	{
		/*
		std::ifstream inputFile(fileName);
		std::string data;

		while (std::getline(inputFile, data, delimiter))
		{
			// TODO
			// Add to list
		}
		*/
	}


	template <typename T>
	List<T>::~List()
	{

	}


	template<typename T>
	void List<T>::pushEnd(T data)
	{
		Node * newNode = new Node;
		newNode->data = data;
		newNode->previous = nullptr;
		newNode->next = nullptr;

		// Check if there is room in the list
		if (size == maximumSize)
		{
			std::cerr << "The list is at it's maximum size!" << std::endl;
			return;
		}

		// If the list is empty this node is the new start and end of the list
		if (size == 0)
		{
			start = newNode;
			end = newNode;
		}
		else
		{
			// Link the new node to the end node
			end->next = newNode;
			newNode->previous = end;

			// Specify the new end of the list
			end = newNode;
		}

		// Increment the size of the list
		size++;
	}


	template<typename T>
	void List<T>::pushStart(T data)
	{
		Node * newNode = new Node;
		newNode->data = data;
		newNode->previous = nullptr;
		newNode->next = nullptr;

		// Check if there is room in the list
		if (size == maximumSize)
		{
			std::cerr << "The list is at it's maximum size!" << std::endl;
			return;
		}

		// If the list is empty this node is the new start and end of the list
		if (size == 0)
		{
			start = newNode;
			end = newNode;
		}
		else
		{
			// Link the new node to the start
			start->previous = newNode;
			newNode->next = start;

			// Specify the new head
			start = newNode;
		}

		// Increment the size of the list
		size++;
	}


	template<typename T>
	void List<T>::print() const
	{
		if (size == 0)
		{
			std::cerr << "Cannot print an empty list!" << std::endl;
			return;
		}

		// Start printing from the start of the list
		Node * currentNode = start;

		// Print the data from each node until the last node
		while (currentNode != end)
		{
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->next;
		}
		// Print the data from the last node too
		std::cout << currentNode->data << std::endl;
	}


	template<typename T>
	unsigned int List<T>::getMaxSize() const
	{
		return maximumSize;
	}


	// Explicit instantiations
	template class List<char>;
	template class List<char*>;
	template class List<bool>;
	template class List<short>;
	template class List<int>;
	template class List<long>;
	template class List<long long>;
	template class List<float>;
	template class List<double>;
	template class List<long double>;

}