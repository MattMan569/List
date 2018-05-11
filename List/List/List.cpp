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
	List<T>::List(std::vector<T> input) : List()
	{
		// Iterate through the vector pushing each data point to the end of the list
		//for (std::vector<T>::iterator i = input.begin(); i != input.end(); ++i)
		//for (auto i = input.begin(); i != input.end(); ++i)
		for (auto i : input)
		{
			//pushEnd(*i);
			pushEnd(i);
		}
	}


	template <typename T>
	List<T>::List(std::string fileName, std::string delimiter)
	{
		// TODO
		// Define
	}

	
	template<typename T>
	List<T>::List(const List & list) : List(list.getMaxSize())
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
		Node * currentNode = start;
		Node * deleteNode;
		int n = 0;

		// Delete from the start of the list to the end
		while (currentNode != end)
		{
			deleteNode = currentNode;
			currentNode = currentNode->next;
			delete deleteNode;
		}
		// Delete the end node
		deleteNode = end;
		delete deleteNode;

		// Reset the start, end, and size
		start = nullptr;
		end = nullptr;
		size = 0;
	}




	template<typename T>
	List<T> & List<T>::operator=(const List<T> & list)
	{
		//this->~List();
		this->removeAll();

		// Start of the list
		Node* currentNode = list.start;

		// Push each node to the end of the list
		while (currentNode != list.end)
		{
			pushEnd(currentNode->data);
			currentNode = currentNode->next;
		}
		pushEnd(currentNode->data);

		return *this;
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
	ReturnCode List<T>::removeAll()
	{
		Node * currentNode = start;
		Node * deleteNode;
		int n = 0;

		// Delete from the start of the list to the end
		while (currentNode != end)
		{
			deleteNode = currentNode;
			currentNode = currentNode->next;
			delete deleteNode;
		}
		// Delete the end node
		deleteNode = end;
		delete deleteNode;

		// Reset the start, end, and size
		start = nullptr;
		end = nullptr;
		size = 0;

		return ReturnCode::OK;
	}


	template<typename T>
	ReturnCode List<T>::removeIf(std::string condition)
	{
		// NOTE: Lambdas may be required
		return ReturnCode();
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
			std::cout << currentNode->data << ",";
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
