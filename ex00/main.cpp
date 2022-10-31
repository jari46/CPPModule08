#include <vector>
#include <list>
#include <deque>

#include <stdexcept>

#include <iostream>

#include "easyfind.hpp"

int main(void) {
	{
		std::vector<int> myVector;

		for (int i = 0 ; i < 10 ; ++i) {
			myVector.push_back(i);
		}

		try {
			std::vector<int>::iterator iter = easyfind(myVector, 4);
			std::cout << "What I found: " << *iter << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::list<int> myList;

		for (int i = 0 ; i < 10 ; ++i) {
			myList.push_back(i);
		}

		try {
			std::list<int>::iterator iter = easyfind(myList, 2);
			std::cout << "What I found: " << *iter << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::deque<int> myDeque;

		for (int i = 0 ; i < 10 ; ++i) {
			myDeque.push_back(i);
		}

		try {
			std::deque<int>::iterator iter = easyfind(myDeque, 42);
			std::cout << "What I found: " << *iter << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
