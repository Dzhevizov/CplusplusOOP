#pragma once

#include <vector>

template<typename T, typename Generator>
class Sequence
{
public:
	class Iterator
	{
		const std::vector<T>& oSequenceElements;
		int iIndex;

		Iterator(const std::vector<T>& oSequenceElements, int iIndex)
			: oSequenceElements(oSequenceElements)
			, iIndex(iIndex) {}

	public:
		static Iterator getBegin(const std::vector<T>& oSequenceElements)
		{
			return Iterator(oSequenceElements, 0);
		}
			
		static Iterator getEnd(const std::vector<T>& oSequenceElements)
		{
			return Iterator(oSequenceElements, -1);
		}

		const T& operator*() const
		{
			return this->oSequenceElements.at(this->iIndex);
		}

		Iterator& operator++()
		{
			this->iIndex++;
			return *this;
		}

		bool operator !=(const Iterator& other) const
		{
			return !(*this == other);
		}

		bool operator ==(const Iterator& other) const
		{
			bool sequencesMatch = this->oSequenceElements == other.oSequenceElements;
			bool bothPositionsAtEnd = isEndIndex(this->iIndex, this->oSequenceElements)
				&& isEndIndex(other.iIndex, other.oSequenceElements);
			bool positionsMatch = this->iIndex == other.iIndex;

			return sequencesMatch && (bothPositionsAtEnd || positionsMatch);
		}

	private:
		static int isEndIndex(int index, const std::vector<T>& oSequenceElements)
		{
			return index == -1 || index == oSequenceElements.size();
		}
	};

private:
	Generator generator;
	std::vector<T> generated;
	
public:
	void generateNext(int numToGenerate)
	{
		for (int i = 0; i < numToGenerate; i++)
		{
			this->generated.push_back(this->generator());
		}
	}

	Iterator begin() const
	{
		return Iterator::getBegin(this->generated);
	}

	Iterator end() const
	{
		return Iterator::getEnd(this->generated);
	}
};