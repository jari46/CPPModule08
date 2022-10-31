#include <stdexcept>
#include <iostream>
#include "Span.hpp"

int main() {
	{/* basic usage */
		Span s1(3);
		s1.addNumber(1);
		s1.addNumber(500);
		s1.addNumber(3);
		std::cout << "shortest: " << s1.shortestSpan() << std::endl;
		std::cout << "longest: " << s1.longestSpan() << std::endl;
	}
	{/* throw exception */
		try {
			Span s1(3);
			s1.addNumber(1);
			std::cout << "shortest: " << s1.shortestSpan() << std::endl;
			std::cout << "longest: " << s1.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{/* addNumber() function template: fill the range */
		Span s1(100);
		s1.addNumber(s1.begin(), s1.begin() + 100, 42);
		for (std::vector<int>::const_iterator iter = s1.begin(); iter != s1.end(); ++iter) {
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
	}
	{/* throw exception */
		try {
			Span s1(100);
			s1.addNumber(s1.begin(), s1.begin() + 150, 42);
			for (std::vector<int>::const_iterator iter = s1.begin(); iter != s1.end(); ++iter) {
				std::cout << *iter << " ";
			}
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
