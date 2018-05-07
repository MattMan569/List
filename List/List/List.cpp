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
	unsigned int List<T>::getMaxSize() const
	{
		return maximumSize;
	}


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