#include "Span.hpp"

int main() {
	{
		Span s1(3);
		s1.addNumber(1);
		s1.addNumber(500);
		s1.addNumber(3);
		std::cout << s1.shortestSpan() << std::endl;
		std::cout << s1.longestSpan() << std::endl;
	}
	{
		try {
			Span s1(3);
			s1.addNumber(1);
			std::cout << s1.shortestSpan() << std::endl;
			std::cout << s1.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span s1(100);
		s1.addNumber(s1.begin(), s1.begin() + 100, 42);
		for (std::vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter) {
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
	}
	{
		try {
			Span s1(100);
			s1.addNumber(s1.begin(), s1.begin() + 150, 42);
			for (std::vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter) {
				std::cout << *iter << " ";
			}
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}