//make the std::stack container iterable!

//Write a MutantStack class. 
//It will be implemented in terms of a std::stack.
//It will offer all its member functions, plus an additional feature: iterators.

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
		~MutantStack(void) {}

		MutantStack<T> &operator=(const MutantStack<T> &other)
		{
			this->c = other.c;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void) { return this->c.begin(); }
		iterator end(void) { return this->c.end(); }
		reverse_iterator rbegin(void) { return this->c.rbegin(); }
		reverse_iterator rend(void) { return this->c.rend(); }

		const_iterator begin(void) const { return this->c.begin(); }
		const_iterator end(void) const { return this->c.end(); }
		const_reverse_iterator rbegin(void) const { return this->c.rbegin(); }
		const_reverse_iterator rend(void) const { return this->c.rend(); }
};

#endif // MUTANT_STACK_HPP
