// File: List.cpp
//

#include "stdafx.h"
#include "List.h"

namespace List
{

	template <typename T>
	List<T>::List(unsigned int maximumListSize) : start(nullptr), end(nullptr)
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
		// TODO
		// Define
	}

	
	template<typename T>
	List<T>::List(const List & list) : List()
	{
		Node * currentNode = list.start;
		
		for (unsigned int i = 0; i < list.getSize(); i++)
		{
			pushEnd(currentNode->data);
			currentNode = currentNode->next;
		}
		
	}
	

	template <typename T>
	List<T>::~List()
	{
		// TODO
		// Define
	}


	template<typename T>
	ReturnCode List<T>::pushEnd(T data)
	{
		Node * newNode = new Node;
		newNode->data = data;
		newNode->previous = nullptr;
		newNode->next = nullptr;

		// Check if there is room in the list
		if (size == maximumSize)
		{
			return ReturnCode::ListFull;
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
		return ReturnCode::OK;
	}


	template<typename T>
	ReturnCode List<T>::pushStart(T data)
	{
		Node * newNode = new Node;
		newNode->data = data;
		newNode->previous = nullptr;
		newNode->next = nullptr;

		// Check if there is room in the list
		if (size == maximumSize)
		{
			return ReturnCode::ListFull;
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
		return ReturnCode::OK;
	}


	template<typename T>
	ReturnCode List<T>::popEnd()
	{
		// Ensure the list is not empty
		if (size == 0)
		{
			return ReturnCode::ListEmpty;
		}

		// If the list has a size of one then the end is also the start
		if (size == 1)
		{
			Node * currentNode = end;
			start = nullptr;
			end = nullptr;
			delete currentNode;
		}
		else
		{
			// Redesignate the end and delete the node
			Node * currentNode = end;
			end = currentNode->previous;
			currentNode->previous->next = nullptr;
			delete currentNode;
		}

		// Decrement the size of the list
		size--;
		return ReturnCode::OK;
	}


	template<typename T>
	ReturnCode List<T>::popStart()
	{
		// Ensure the list is not empty
		if (size == 0)
		{
			return ReturnCode::ListEmpty;
		}

		// If the list has a size of one then the start is also the end
		if (size == 1)
		{
			Node * currentNode = start;
			start = nullptr;
			end = nullptr;
			delete currentNode;
		}
		else
		{
			// Redesignate the start and delete the node
			Node * currentNode = start;
			start = currentNode->next;
			currentNode->next->previous = nullptr;
			delete currentNode;
		}

		// Decrement the size of the list
		size--;
		return ReturnCode::OK;
	}


	template<typename T>
	ReturnCode List<T>::print() const
	{
		// Ensure the list is not empty
		if (size == 0)
		{
			return ReturnCode::ListEmpty;
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

		return ReturnCode::OK;
	}


	template<typename T>
	typename List<T>::Node * List<T>::getStart() const
	{
		return start;
	}


	template<typename T>
	typename List<T>::Node * List<T>::getEnd() const
	{
		return end;
	}


	template<typename T>
	unsigned int List<T>::getMaxSize() const
	{
		return maximumSize;
	}


	template<typename T>
	unsigned int List<T>::getSize() const
	{
		return size;
	}


	// Explicit instantiations
	template class List<char>;
	template class List<char*>;
	template class List<std::string>;
	template class List<bool>;
	template class List<short>;
	template class List<int>;
	template class List<long>;
	template class List<long long>;
	template class List<float>;
	template class List<double>;
	template class List<long double>;

}