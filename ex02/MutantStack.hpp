//make the std::stack container iterable!

//Write a MutantStack class.
//It will be implemented in terms of a std::stack.
//It will offer all its member functions, plus an additional feature: iterators.

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

/*

		stack synopsis

template <class T, class Container = deque<T>>												// if ( deque<int> ),
class stack
{
public:
    typedef Container                                container_type;	// deque<int>
    typedef typename container_type::value_type      value_type;			// int
    typedef typename container_type::reference       reference;				// int&
    typedef typename container_type::const_reference const_reference;	// const int&
    typedef typename container_type::size_type       size_type;				// unsigned integral type (usually size_t))

protected:
    container_type c; // 이 멤버변수로 deque의 메소드를 이용한 사용자 정의 함수를 추가할 수 있다.

public:
    size_type size() const;
    const_reference top() const;
    void push(const value_type& x);
    void pop();

		stack& operator=(const stack& __q) {c = __q.c; return *this;}
}

*/

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {}
		MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
		~MutantStack(void) {}

		MutantStack<T> &operator=(const MutantStack<T> &other)
		{
			this->c = other.c;
			return (*this);
		}

		/* just to make it readable! */
		typedef	typename std::stack<T>::container_type::iterator								iterator; // deque<int>::iterator
		typedef	typename std::stack<T>::container_type::reverse_iterator				reverse_iterator;
		typedef	typename std::stack<T>::container_type::const_iterator					const_iterator;
		typedef	typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		// added functions: 4 kinds of iterators
		// (!) cbegin(), crbegin(), ... are not in C++98, and not needed if you return like below
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
