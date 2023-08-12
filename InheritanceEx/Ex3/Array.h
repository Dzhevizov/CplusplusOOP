#pragma once

template <typename T>
class Array
{
public:
	class Iterator
	{
		T* m_array;
		int m_index;
		int& m_size;

	public:
		Iterator(T* arrayPtr, int index, int size) : m_array(arrayPtr), m_index(index), m_size(size) {}

		T& operator*() const
		{
			return *m_array;
		}

		Iterator operator++()
		{
			m_array++;
			m_index++;
			return *this;
		}

		bool operator!=(const Iterator& other) const
		{
			return !(*this == other);
		}

		bool operator==(const Iterator& other) const
		{
			bool sequencesMatch = this->m_array[0] == other.m_array[0];
			bool bothPositionsAtEnd = isEndIndex(this->m_index, this->m_array, this->m_size)
				&& isEndIndex(other.m_index, other.m_array, other.m_size);
			bool positionsMatch = this->m_index == other.m_index;

			return sequencesMatch && (bothPositionsAtEnd || positionsMatch);
		}

	private:
		const int isEndIndex(int index, const T* m_array, int size) const
		{
			return index == -1 || index == size;
		}
	};
	
private:

	int m_size;
	T* m_array;

public:
	Array<T>(int size) : m_size(size)
	{
		m_array = new T[size];
		for (int i = 0; i < size; i++) // initialize the array with zeros
		{
			m_array[i] = 0;
		}
	}

	~Array<T>()
	{
	}

	const int getSize() const
	{
		return m_size;
	}

	int& operator[](int index)
	{
		return m_array[index];
	}

	Iterator begin() const
	{
		return Iterator(m_array, 0, m_size);
	}

	Iterator end() const
	{
		return Iterator(m_array, m_size, m_size);
	}

	Array& operator=(const Array& other)
	{
		if (this != &other) // avoid self-assignment
		{
			delete[] m_array; // free the old memory
			m_size = other.m_size; // copy the size
			m_array = new T[m_size]; // allocate new memory
			for (size_t i = 0; i < m_size; i++) // copy the elements
			{
				m_array[i] = other.m_array[i];
			}
		}
		return *this; // return a reference to this object
	}
};


/*
3
4 1 -2 3 4
1 505
2 13 42
*/