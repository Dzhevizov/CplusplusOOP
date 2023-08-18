#ifndef TYPED_STREAM_H
#define TYPED_STREAM_H

#include <vector>
#include <string>

template <typename T> 
class TypedStream
{
public:
	TypedStream(const std::string& input) 
		: input(input)
		, stream(input) {};

	virtual TypedStream<T>& operator>>(T& v) = 0;

	std::vector<T> readToEnd()
	{
		std::vector<T> result;
		T el;
		
		while (*this >> el)
		{
			result.push_back(el);
		}

		return result;
	}

	operator bool() const
	{
		return !stream.fail();
	}

protected:
	std::stringstream stream;
	std::string input;

};
#endif // !TYPED_STREAM_H
