#pragma once

template <typename T>
void printVector(const std::vector<T>& vector)
{
	for (const T& el : vector)
	{
		std::cout << el << " ";
	}

	std::cout << std::endl;
}