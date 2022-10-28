#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

//can store a maximum of N integers
class Span
{
	private:
		Span(void);
		std::vector<int> mStorage;
		unsigned int mMax;

	public:
		Span(unsigned int max);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		//add a single number to the Span. 
		//It will be used in order to fill it
		void addNumber(int n);

		int shortestSpan(void);
		int longestSpan(void);

		std::vector<int>::iterator begin();
		std::vector<int>::iterator end();

		template<typename T>
		void addNumber(T begin, T end, const int& value) {
			if ((mMax - (unsigned int)mStorage.size()) < std::distance(begin, end))
				throw std::logic_error("no enough space");
			mStorage.insert(begin, std::distance(begin, end), value);
		}
};