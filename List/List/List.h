// File: List.h
//
// Doubly linked list in the style of std::List

#pragma once

namespace List
{
	// Using the same value as std list for the maximum number of nodes
	const unsigned int max_nodes = 357913941U;

	// Possible return codes of List functions
	enum class ReturnCode
	{
		OK,				// No error
		ListEmpty,		// The function cannot continue due to the list being empty
		ListFull,		// The function cannot continue due to the list being full
		NotFound		// No node was found when searching or deleting
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
		List(unsigned int maximumSize = max_nodes);

		// Create a list from a std::vector
		List(std::vector<T> input);

		// Create a list from a file with a specified delimiter
		// that separates the list items, such as a comma
		List(std::string fileName, std::string delimiter);

		// Create a copy of a list
		List(const List& list);

		// Delete all nodes within the list
		~List();


		// Overloaded assignment operator
		List & operator=(const List & list);
		

		// Add a node to the end of the list
		ReturnCode pushEnd(T data);

		// Add a node to the start of the list
		ReturnCode pushStart(T data);

		// Delete the end node of the list
		ReturnCode popEnd();

		// Delete the start node of the list
		ReturnCode popStart();


		// Remove all elements
		ReturnCode removeAll();

		// Remove the first element matching the given data
		ReturnCode remove(T data);


		// Print the contents of the list from start to end
		ReturnCode print() const;


		// Get the pointer to the start of the list
		typename List<T>::Node * getStart() const;

		// Get the pointer to the end of the list
		typename List<T>::Node * getEnd() const;

		// Return the maximum size of the list
		unsigned int getMaxSize() const;

		// Return the current size of the list
		unsigned int getSize() const;


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
