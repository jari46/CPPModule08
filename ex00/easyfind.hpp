#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>//find
#include <stdexcept>

//The first argument has type T and the second argument is an integer.
//Assuming T is a container of integers,
//this function has to find the first occurrence of the second parameter
//in the first parameter.

template <typename T/*container of integers*/>
typename T::iterator easyfind(T &cont, int needle) {
  typename T::iterator iter = std::find(cont.begin(), cont.end(), needle);
  if (iter == cont.end())
    throw std::logic_error("Error: no such data");
  else
    return iter;
}

#endif // EASYFIND_HPP
