#pragma once
#include "Resource.h"
#include <map>


namespace SoftUni
{
	class Lecture
	{
		map<int, Resource> recources;
		map<ResourceType, int> resourcesByType;

	public:

		class It
		{
			map<int, Resource>::iterator it;

		public:

			It(map<int, Resource>::iterator iter) : it(iter)
			{
			}

			It& operator++()
			{
				++it;
				return *this;
			}

			bool operator!=(const It& other) const
			{
				return this->it != other.it;
			}

			Resource operator*() const
			{
				return it->second;
			}
		};

		It begin()
		{
			return It(recources.begin());
		}

		It end()
		{
			return It(recources.end());
		}

		Lecture& operator<<(const Resource& res)
		{
			auto it = recources.find(res.getId());
			if (it != recources.end())
			{
				ResourceType prevType = it->second.getType();
				resourcesByType[prevType]--;
				if (resourcesByType[prevType] == 0)
					resourcesByType.erase(prevType);
			}

			recources[res.getId()] = res;
			resourcesByType[res.getType()]++;

			return *this; 
		};

		void initResourceTypes(vector<ResourceType>& resTypes) const
		{
			resTypes.clear();

			for (auto cur : resourcesByType)
			{
				resTypes.push_back(cur.first);
			}
		}

		int operator[](ResourceType resType)
		{
			return resourcesByType[resType];
		}
	};

	void operator<<(vector<ResourceType>& resTypes, Lecture& lectures)
	{
		lectures.initResourceTypes(resTypes);
	}
};