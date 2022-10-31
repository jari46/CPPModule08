#include <algorithm>//sort, max_element, min_element
#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int max) : mMax(max) {}

Span::Span(const Span &other) : mStorage(other.mStorage), mMax(other.mMax) {}

Span &Span::operator=(const Span &other) {
    mMax = other.mMax;
		mStorage = other.mStorage;
    return (*this);
}

Span::~Span(void) {}

void Span::addNumber(int number)
{
    if (mMax < mStorage.size() + 1)
        throw std::logic_error("Span is full");
    else
        mStorage.push_back(number);
}

int Span::shortestSpan(void) {
  if (mStorage.size() < 2)
    throw std::logic_error("there are no numbers stored, or only one");

  std::vector<int> temp(mStorage);
  std::sort(temp.begin(), temp.end());
	int minDistance = longestSpan();
	for (std::size_t i = 0; i < temp.size() - 1; ++i) {
		if (temp[i + 1] - temp[i] < minDistance)
			minDistance = temp[i + 1] - temp[i];/*reset*/
	}
	return minDistance;
}

int Span::longestSpan(void) {
  if (mStorage.size() < 2)
    throw std::logic_error("there are no numbers stored, or only one");
	return *std::max_element(mStorage.begin(), mStorage.end()) - *std::min_element(mStorage.begin(), mStorage.end());
}

std::vector<int>::iterator Span::begin() {
  return mStorage.begin();
}
std::vector<int>::iterator Span::end() {
  return mStorage.end();
}
