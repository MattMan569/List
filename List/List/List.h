// File: List.h
//
// Doubly linked list in the style of std::List

#pragma once

namespace List
{

	// Possible return codes of List functions
	enum class ReturnCode
	{
		OK,
		ListEmpty,
		ListFull
	};

	template <typename T>
	class List
	{
		// Nodes contained within the list
		struct Node
		{
			// Pointer to the previous node
			Node * previous;

			// Pointer to the next node
			Node * next;

			// Data within this node
			T data;
		};

	public:
		// Create an empty list
		List(int maximumSize = UINT_MAX);

		// Create a list from a std::vector
		List(std::vector<T> input);

		// Create a list from a file with a specified delimiter
		// that separates the list items, such as a comma
		List(std::string fileName, std::string delimiter);

		// Delete all nodes within the list
		~List();
		

		// Add a node to the end of the list
		// Returns false on failure
		ReturnCode pushEnd(T data);

		// Add a node to the start of the list
		// Returns false on failure
		ReturnCode pushStart(T data);

		// Delete the end node of the list
		// Returns false if there is no node to pop
		ReturnCode popEnd();

		// Delete the start node of the list
		// Returns false if there is no node to pop
		ReturnCode popStart();


		// Print the contents of the list from start to end
		// Returns false if the list is empty
		ReturnCode print() const;

		// Return the maximum size of the list
		unsigned int getMaxSize() const;

	private:
		// Pointer to the start of the list
		Node * start;

		// Pointer to the end of the list
		Node * end;

		// Number of nodes within the list
		unsigned int size;

		// The maximum number of nodes the list may contain
		unsigned int maximumSize;
	};

}